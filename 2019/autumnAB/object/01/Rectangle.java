public class Rectangle {
  int left;   // 左端の座標
  int bottom; // 下端の座標
  int width;  // 幅
  int height; // 高さ
 
  Rectangle(int left, int bottom, int width, int height) {
    this.left = left;
    this.bottom = bottom;
    this.width = width;
    this.height = height;
  }
  void printRectangle() {
      System.out.print("左下(" + left + ", " + bottom + "), ");
      System.out.println("右上(" + (left + width)  + ", " + (bottom + height) + ")");
  }
  int getArea() {
      // 面積を返す
      return width*height;
  }

  boolean isLarger(Rectangle r) {
      // thisの面積がrの面積より大きければ true ，そうでなければ falseを返す．
      return (this.getArea() > r.getArea());
  }
 
  boolean contains(Point p) {
      // pが長方形の中にあれば(端の線上にある場合も含む) true を返す．
      return ((this.left < p.x && p.x < this.left+width) && (this.bottom < p.y && p.y < this.bottom+height));
  }
}