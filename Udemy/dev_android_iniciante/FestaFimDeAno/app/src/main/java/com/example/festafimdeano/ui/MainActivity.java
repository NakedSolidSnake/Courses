package com.example.festafimdeano.ui;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.festafimdeano.R;
import com.example.festafimdeano.constant.FimDeAnoConstants;
import com.example.festafimdeano.data.SecurityPreferences;

import java.text.SimpleDateFormat;
import java.util.Calendar;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private ViewHolder mViewHolder = new ViewHolder();
    private static SimpleDateFormat SIMPLE_DATE_FORMAT = new SimpleDateFormat("dd/MM/yyyy");
    private SecurityPreferences mSecurityPreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.mViewHolder.textToday = findViewById(R.id.text_today);
        this.mViewHolder.textDaysLeft = findViewById(R.id.text_days_left);
        this.mViewHolder.btConfirm = findViewById(R.id.bt_confirm);

        this.mSecurityPreferences = new SecurityPreferences(this);

        this.mViewHolder.btConfirm.setOnClickListener(this);

        this.mViewHolder.textToday.setText(SIMPLE_DATE_FORMAT.format(Calendar.getInstance().getTime()));
        String daysLeft = String.format("%s %s", String.valueOf(this.getDaysLeft()), this.getString(R.string.dias));
        this.mViewHolder.textDaysLeft.setText(daysLeft);

        this.verifyPresence();
    }

    @Override
    public void onClick(View v) {
        if(v.getId() == R.id.bt_confirm){

            String presence =  this.mSecurityPreferences.getStoredString(FimDeAnoConstants.PRESENCE_KEY);

            Intent intent = new Intent(this, DetailsActivity.class);
            //passando parametros para uma activity
            intent.putExtra(FimDeAnoConstants.PRESENCE_KEY, presence);
            startActivity(intent);
        }
    }

    @Override
    protected void onStart() {
        super.onStart();
    }

    @Override
    protected void onResume() {
        super.onResume();
        verifyPresence();
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    private void verifyPresence(){
        String presence = this.mSecurityPreferences.getStoredString(FimDeAnoConstants.PRESENCE_KEY);
        if(presence.equals("")){
            this.mViewHolder.btConfirm.setText(getString(R.string.no_confirm));
        }else if(presence.equals(FimDeAnoConstants.CONFIRMATION_YES)){
            this.mViewHolder.btConfirm.setText(getString(R.string.yes));
        }else{
            this.mViewHolder.btConfirm.setText(getString(R.string.no));
        }
    }

    private int getDaysLeft(){
        Calendar calendar = Calendar.getInstance();

        int today = calendar.get(Calendar.DAY_OF_YEAR);

        Calendar calenderLastDay = Calendar.getInstance();
        int dayMax = calenderLastDay.getActualMaximum(Calendar.DAY_OF_YEAR);

        return dayMax - today;
    }

    private static class ViewHolder{
        TextView textToday;
        TextView textDaysLeft;
        Button btConfirm;
    }
}
