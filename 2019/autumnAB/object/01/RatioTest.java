public class RatioTest {
  public static void main(String[] args) {
      Ratio r1 = new Ratio(1, 2); // 1/2
      Ratio r2 = new Ratio(1, 4); // 1/4

      Ratio r3 = r1.multiply(r2); // (1/2) * (1/4)
      System.out.println(r3);

      Ratio r4 = r1.add(r2);    // (1/2) + (1/4)
      System.out.println(r4);

      Ratio r5 = r1.subtract(r2);   // (1/2) - (1/4)
      System.out.println(r5);

      Ratio r6 = r1.divide(r2);   // (1/2) / (1/4)
      System.out.println(r6);

      Ratio r7 = r2.multiply(3).divide(2).add(1).multiply(2).subtract(1);
      // r7 = ((1/4) * 3 / 2 + 1) * 2 - 1
      System.out.println(r7);
  }
}