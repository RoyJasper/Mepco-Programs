android:onClick="RadioButtonClicked" >
underneath both your male and female radioGroup child elements Like so:

android:id="@+id/radio_female"
android:text="@string/radio_female"
android:onClick="RadioButtonClicked"
Now that that is done, in your MainActivity add this code:

//Note the name of the method must match the xml onClick value in this case 'RadioButtonClicked'

public void RadioButtonClicked(View view) {

//This variable will store whether the user was male or female
String userGender=""; 
// Check that the button is  now checked?
boolean checked = ((RadioButton) view).isChecked();

// Check which radio button was clicked
switch(view.getId()) {
    case R.id.radio_female:
        if (checked)
            userGender = "female";
        break;
    case R.id.radio_male:
        if (checked)
           userGender = "male";
        break;
}

//Now insert it into your database using userGender instead of gender

pf.execSQL....+userGender
