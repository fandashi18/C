package com.fmy;

public class App {
    public native int add(int x,int y);
    public static void main(String[] args) throws Exception {
        System.load("/home/fanmingyang/JavaProjects/JNI/src/App.so");
        System.out.println("1 + 1 = " + new App().add(1, 1));
    }
}
