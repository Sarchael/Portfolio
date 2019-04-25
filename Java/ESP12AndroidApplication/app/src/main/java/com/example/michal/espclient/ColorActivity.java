package com.example.michal.espclient;

import android.content.Intent;
import android.graphics.Color;
import android.os.Build;
import android.support.annotation.RequiresApi;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

public class ColorActivity extends AppCompatActivity {

    @RequiresApi(api = Build.VERSION_CODES.N)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_color);

        Button colorB = (Button) findViewById(R.id.colorButton);
        SeekBar rBar = (SeekBar) findViewById(R.id.redSlider);
        SeekBar gBar = (SeekBar) findViewById(R.id.greenSlider);
        SeekBar bBar = (SeekBar) findViewById(R.id.blueSlider);

        Bundle colorData = getIntent().getExtras();

        if(colorData!=null){
            rBar.setProgress(colorData.getInt("red"), true);
            gBar.setProgress(colorData.getInt("green"), true);
            bBar.setProgress(colorData.getInt("blue"), true);
        }

        colorB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SeekBar rBar = (SeekBar) findViewById(R.id.redSlider);
                SeekBar gBar = (SeekBar) findViewById(R.id.greenSlider);
                SeekBar bBar = (SeekBar) findViewById(R.id.blueSlider);

                Intent intent = new Intent(ColorActivity.this, MainActivity.class);
                intent.putExtra("red", rBar.getProgress());
                intent.putExtra("green", gBar.getProgress());
                intent.putExtra("blue", bBar.getProgress());
                startActivity(intent);
                intent = null;
            }
        });
    }
}
