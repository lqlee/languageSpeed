/*
 * javac DotProduct.java
 * java DotProduct
 *
 */

import java.util.Random;

public class DotProduct {
  public static void main(String[] args) {
    final int LEN = 10000000;
    Random random = new Random(); // Create a Random object

    long start = System.currentTimeMillis();

    var arr = new double[LEN];
    var brr = new double[LEN];
    for (int i = 0; i < LEN; i ++ ) {
      arr[i] = random.nextDouble();
      brr[i] = random.nextDouble();
    }

    long mid = System.currentTimeMillis();

    double res = 0.0;
    for (int i = 0; i < LEN; i ++ ) {
      res += arr[i] * brr[i];
    }

    long end = System.currentTimeMillis();

    System.out.println(" JAVA  LEN : " + LEN + ", init : " 
      + (mid - start) + ", dot product : " + (end - mid) 
      + " ms, total : " + (end - start) + " ms" );
  }
}

