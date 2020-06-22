public class Point {
  int x, y;
  Point(int x, int y) {
      this.x = x;
      this.y = y;
  }
  void printPoint() {
      System.out.println("座標(" + x + ", " + y + ")");
  }
}