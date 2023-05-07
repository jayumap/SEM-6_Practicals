package SymmetricKey;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;
import java.util.Scanner;

public class DES {
    private SecretKey key;
    private final int KEY_SIZE = 56;
    private final int DATA_LENGTH = 128;
    private Cipher encryptionCipher;
    private Cipher decryptionCipher;

    public void init() throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
        keyGenerator.init(KEY_SIZE);
        key = keyGenerator.generateKey();

        encryptionCipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
        encryptionCipher.init(Cipher.ENCRYPT_MODE, key);

        decryptionCipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
        decryptionCipher.init(Cipher.DECRYPT_MODE, key);
    }

    public String encrypt(String data) throws Exception {
        byte[] dataInBytes = data.getBytes();
        byte[] encryptedBytes = encryptionCipher.doFinal(dataInBytes);
        return encode(encryptedBytes);
    }

    public String decrypt(String encryptedData) throws Exception {
        byte[] dataInBytes = decode(encryptedData);
        byte[] decryptedBytes = decryptionCipher.doFinal(dataInBytes);
        return new String(decryptedBytes);
    }

    public String getKeyAsString() {
        return encode(key.getEncoded());
    }

    private String encode(byte[] data) {
        return Base64.getEncoder().encodeToString(data);
    }

    private byte[] decode(String data) {
        return Base64.getDecoder().decode(data);
    }

    public static void main(String[] args) {
        try {
            DES des_encryption = new DES();
            des_encryption.init();

            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the plain text: ");
            String plainText = scanner.nextLine();

            String encryptedData = des_encryption.encrypt(plainText);
            String decryptedData = des_encryption.decrypt(encryptedData);
            String keyString = des_encryption.getKeyAsString();

            System.out.println("\n-------------------------------------------------------");
            System.out.printf("%-20s%-35s\n", "| Plain Text:", "| " + plainText);
            System.out.printf("%-20s%-35s\n", "| Key:", "| " + keyString);
            System.out.printf("%-20s%-35s\n", "| Encrypted Text:", "| " + encryptedData);
            System.out.printf("%-20s%-35s\n", "| Decrypted Text:", "| " + decryptedData);
            System.out.println("-------------------------------------------------------");
            System.out.printf("%-20s%-35s\n", "| Sender's side:", "| " + plainText);
            System.out.printf("%-20s%-35s\n", "| Encrypted Text:", "| " + encryptedData);
            System.out.printf("%-20s%-35s\n", "| Receiver's side:", "| " + decryptedData);
            System.out.println("-------------------------------------------------------\n");
        } catch (Exception ignored) {
        }
    }
}



// package SymmetricKey;
// import java.security.SecureRandom;
// import javax.crypto.Cipher;
// import javax.crypto.KeyGenerator;
// import javax.crypto.SecretKey;
// import javax.crypto.spec.SecretKeySpec;
// import java.util.Random;
// import java.util.*;

// public class DES {
//     byte[] skey = new byte[1000];
//     String skeyString;
//     static byte[] raw;
//     String inputMessage, encryptedData, decryptedMessage;
//     StringBuffer sb = new StringBuffer();

//     Scanner sc = new Scanner(System.in);
//     public DES() {
//         try {

//             generateSymmetricKey();
            
//             System.out.print("Enter message to encrypt: ");
            
//             sb.append(sc.nextLine());
            
//             inputMessage = sb.toString();
            
//             byte[] ibyte = inputMessage.getBytes();
//             byte[] ebyte = encrypt(raw, ibyte);
//             String encryptedData = new String(ebyte);
//             System.out.println("Encrypted message: " + encryptedData);
            
//             byte[] dbyte = decrypt(raw, ebyte);
//             String decryptedMessage = new String(dbyte);
//             System.out.println("Decrypted message: " + decryptedMessage);
//         } catch (Exception e) {
//             System.out.println(e);
//         }
//     }

//     void generateSymmetricKey() {
//         try {
//             Random r = new Random();
//             int num = r.nextInt(10000);
//             String knum = String.valueOf(num);
//             byte[] knumb = knum.getBytes();
//             skey = getRawKey(knumb);
//             skeyString = new String(skey);
//             System.out.println("DES Symmetric key = " + skeyString);
//         } catch (Exception e) {
//             System.out.println(e);
//         }
//     }

//     private static byte[] getRawKey(byte[] seed) throws Exception {
//         KeyGenerator kgen = KeyGenerator.getInstance("DES");
//         SecureRandom sr = SecureRandom.getInstance("SHA1PRNG");
//         sr.setSeed(seed);
//         kgen.init(56, sr);
//         SecretKey skey = kgen.generateKey();
//         raw = skey.getEncoded();
//         return raw;
//     }

//     private static byte[] encrypt(byte[] raw, byte[] clear) throws Exception {
//         SecretKeySpec skeySpec = new SecretKeySpec(raw,
//                 "DES");
//         Cipher cipher = Cipher.getInstance("DES");
//         cipher.init(Cipher.ENCRYPT_MODE, skeySpec);
//         byte[] encrypted = cipher.doFinal(clear);
//         return encrypted;
//     }

//     private static byte[] decrypt(byte[] raw, byte[] encrypted)
//             throws Exception {
//         SecretKeySpec skeySpec = new SecretKeySpec(raw,
//                 "DES");
//         Cipher cipher = Cipher.getInstance("DES");
//         cipher.init(Cipher.DECRYPT_MODE, skeySpec);
//         byte[] decrypted = cipher.doFinal(encrypted);
//         return decrypted;
//     }

//     public static void main(String args[]) {
//         DES des = new DES();
//     }
// }

