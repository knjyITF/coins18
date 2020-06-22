public class RectangleTest {
  public static void main(String[] args) {
      Rectangle r1 = new Rectangle(5, 3, 10, 20);
      Rectangle r2 = new Rectangle(9, 13, 12, 10);
      Point[] p = {new Point(4, 30), new Point(6, 30), new Point(20, 30),
                   new Point(4, 20), new Point(6, 20), new Point(20, 20),
                   new Point(4, 2), new Point(6, 2), new Point(20, 2)};
      System.out.print("r1: ");
      r1.printRectangle();
      System.out.print("r2: ");
      r2.printRectangle();

      System.out.print("r1はr2より");
      if (r1.isLarger(r2)) {
          System.out.println("大きい．");
      } else {
          System.out.println("大きくない．");
      }

      for (int i = 0; i < p.length; i++) {
          p[i].printPoint();
          if (r1.contains(p[i])) {
              System.out.println("r1の中．");
          }
          if (r2.contains(p[i])) {
              System.out.println("r2の中．");
          }
      }
  }
}