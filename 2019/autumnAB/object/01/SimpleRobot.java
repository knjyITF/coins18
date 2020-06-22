public class SimpleRobot  {
  // ロボットの内部状態を表すデータ
  double x, y;    // 現在の座標．
  double heading; // 角度(0〜360)．0は東(右)，90は北(上)を表す．

  public SimpleRobot() {
      x = y = 0.0;
      heading = 0.0;
  }
  public void setHeading(double heading) {
      this.heading = heading;
  }
  public void turnLeft(double degree) {
      setHeading(heading + degree);
  }
  public void turnRight(double degree) {
      turnLeft(-degree);
  }
  public void moveTo(double x, double y) {
      System.out.println(this.x+" "+this.y);
      this.x = x;
      this.y = y;
      System.out.println(this.x+" "+this.y);
  }
  public void moveForward(double step) {
      double radian = heading / 180.0 * Math.PI;
      moveTo(this.x + Math.cos(radian) * step,
             this.y + Math.sin(radian) * step);
  }
}