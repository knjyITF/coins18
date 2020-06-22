public class Triangle {
  public static void main(String[] args) {
      SimpleRobot robot = new SimpleRobot();
      for (int i = 0; i < 3; i++) {
          robot.moveForward(100);  // 「前へ100歩進め」
          robot.turnLeft(120);     // 「左へ120度回れ」
      }
  }
}