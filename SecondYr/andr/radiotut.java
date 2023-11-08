package com.example.saira_000.myapplication;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.ImageButton;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;
import android.widget.ToggleButton;

public class MainActivity extends ActionBarActivity {
   RadioGroup rg1;
   RadioButton rb1;
   Button b1;
   
   protected void onCreate(Bundle savedInstanceState) {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.activity_main);
      addListenerRadioButton();
   }
   
   private void addListenerRadioButton() {
      rg1 = (RadioGroup) findViewById(R.id.radioGroup);
      b1 = (Button) findViewById(R.id.button2);
      b1.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View v) {
            int selected=rg1.getCheckedRadioButtonId();
            rb1=(RadioButton)findViewById(selected);
            Toast.makeText(MainActivity.this,rb1.getText(),Toast.LENGTH_LONG).show();
         }
      });
   }
   
   @Override
   public boolean onCreateOptionsMenu(Menu menu) {
      // Inflate the menu; this adds items to the action bar if it is present.
      getMenuInflater().inflate(R.menu.menu_main, menu);
      return true;
   }
   
   @Override
   public boolean onOptionsItemSelected(MenuItem item) {
      // Handle action bar item clicks here. The action bar will
      // automatically handle clicks on the Home/Up button, so long
      // as you specify a parent activity in AndroidManifest.xml.
      
      int id = item.getItemId();
      
      //noinspection SimplifiableIfStatement
      if (id == R.id.action_settings) {
         return true;
      }
      return super.onOptionsItemSelected(item);
   }
}
