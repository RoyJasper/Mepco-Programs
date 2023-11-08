import java.io.*;
import java.util.*;
public class Datatypes {

	public static void main(String[] args) {
		String s1 = "DROPIT";
		String s2 = "SECRETKEY";
		System.out.println("Plain Text Before Encryption: " +s2.compareTo(s1) );
			}

	private static String encrypt(String plainText, String secretKey) {
		StringBuffer encryptedString = new StringBuffer();
		int encryptedInt;
		for (int i = 0; i < plainText.length(); i++) {
			int plainTextInt = (int) (plainText.charAt(i) - 'A');
			int secretKeyInt = (int) (secretKey.charAt(i) - 'A');
			encryptedInt = (plainTextInt + secretKeyInt) % 26;
			encryptedString.append((char) ((encryptedInt) + (int) 'A'));
		}
		return encryptedString.toString();
	}

	private static String decrypt(String decryptedText, String secretKey) {
		StringBuffer decryptedString = new StringBuffer();
		int decryptedInt;
		for (int i = 0; i < decryptedText.length(); i++) {
			int decryptedTextInt = (int) (decryptedText.charAt(i) - 'A');
			int secretKeyInt = (int) (secretKey.charAt(i) - 'A');
			decryptedInt = decryptedTextInt - secretKeyInt;
			if (decryptedInt < 1)
				decryptedInt += 26;
			decryptedString.append((char) ((decryptedInt) + (int) 'A'));
		}
		return decryptedString.toString();
	}
}