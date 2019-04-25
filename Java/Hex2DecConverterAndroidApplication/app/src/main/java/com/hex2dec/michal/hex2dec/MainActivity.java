package com.hex2dec.michal.hex2dec;

import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button button;
    private EditText numberToConvertion;
    private TextView result;
    private RadioButton hex2Dec;
    private RadioButton dec2Hex;
    private Model model = new Model();

    private MainActivity getActivity() {
        return this;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button)findViewById(R.id.button);
        numberToConvertion = (EditText)findViewById(R.id.numberToConvertion);
        result = (TextView)findViewById(R.id.result);
        hex2Dec = (RadioButton)findViewById(R.id.hex2Dec);
        dec2Hex = (RadioButton)findViewById(R.id.dec2Hex);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                result.setText("");

                if(hex2Dec.isChecked()) {
                    model.setMode("1");
                }
                else if (dec2Hex.isChecked()) {
                    model.setMode("0");
                }

                model.setNumber(numberToConvertion.getText().toString());

                try {
                    model.calculate();
                    result.setText(model.getResult());
                } catch (MyException e) {
                    //e.printStackTrace();
                    Toast.makeText(getActivity(), e.getMessage(), Toast.LENGTH_LONG).show();
                }
            }
        });
    }
}
