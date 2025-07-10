package util;

import java.io.*;

public class IdGenerator  {
    String fileName = "last_id.txt";

    public static int getNextID() {

    }

    public static void saveLastID(int id) {

    }

    private boolean fileExist() {
        return new File(fileName).exists();
    }

    public void ensureFileExist(){

        File file = new File(fileName);
        if(!fileExist()) {
            try {
                String filePath = "C:\\programming\\java\\proyectsJava\\marco-dev-portfolio\\java\\ServiceManager\\src\\util\\";
                File fileNew = new File(filePath + fileName);

                if(fileNew.createNewFile()) {
                    System.out.println("File created with succes");
                }else {
                    System.out.println("File name already exists");
                }

            } catch(Exception e) {
                System.out.println("Failed to create the file");
            }
        }
    }
}

