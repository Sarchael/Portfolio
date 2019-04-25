package com.example.michal.espclient;

import android.content.Intent;
import android.os.StrictMode;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.text.DecimalFormat;
import java.text.NumberFormat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);

        final Connection connection = new Connection();
        Button ledB = (Button) findViewById(R.id.ledButton);
        Button sensorB = (Button) findViewById(R.id.sensorsButton);
        Button colorB = (Button) findViewById(R.id.colorButton);

        final int rValue;
        final int gValue;
        final int bValue;

        Bundle colorData = getIntent().getExtras();

        final String RGB;

        if(colorData == null){
            rValue = 0;
            gValue = 0;
            bValue = 0;
        }
        else{
            rValue = colorData.getInt("red");
            gValue = colorData.getInt("green");
            bValue = colorData.getInt("blue");

            if(colorData.containsKey("red") && (rValue != 0 || gValue !=0 || bValue != 0)){
                TextView field = (TextView) findViewById(R.id.responseField);
                field.setText("Ustawiłeś kolor!\nNaciśnij przycisk \"STERUJ DIODĄ\"");
            }
        }

        NumberFormat formatter = new DecimalFormat("000");
        RGB = formatter.format(rValue) + "" + formatter.format(gValue) + "" + formatter.format(bValue);

        ledB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TextView field = (TextView) findViewById(R.id.responseField);
                if(rValue != 0 || gValue !=0 || bValue != 0) {
                    String answer = connection.action(2, RGB);
                    field.setText(answer);
                }
                else{
                    field.setText("Najpierw ustaw kolor!");
                }
            }
        });

        sensorB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TextView field = (TextView) findViewById(R.id.responseField);
                String answer = connection.action(1, RGB);
                field.setText(answer);
            }
        });

        colorB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //TextView field = (TextView) findViewById(R.id.responseField);
                //field.setText("Przełączam widok!");
                Intent intent = new Intent(MainActivity.this, ColorActivity.class);
                intent.putExtra("red", rValue);
                intent.putExtra("green", gValue);
                intent.putExtra("blue", bValue);
                startActivity(intent);
                intent = null;
            }
        });
    }

    @Override
    protected void onStop(){
        super.onStop();
        TextView field = (TextView) findViewById(R.id.responseField);
        field.setText("");
    }

}
