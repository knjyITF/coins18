public class Ratio {
  private long num;    // 分子
  private long denom;  // 分母

  public Ratio(long num, long denom) {
      if (denom < 0) {
          num *= -1;
          denom *= -1;
      }
      long g = gcd(num, denom);    // 約分するために最大公約数を求める．
      this.num = num / g;
      this.denom = denom / g;
  }
  // クラスの外には見せないメソッド
  private long gcd(long p, long q) {
    // 最大公約数を計算する．
    long tmp;
    while ((tmp = p % q) != 0) {
      p = q;
      q = tmp;
    }
    return q;
  }
  private Ratio multiply(long num, long denom) {
      long n = this.num * num;
      long d = this.denom * denom;
      return new Ratio(n, d);
  }
  private  Ratio add(long num, long denom) {
      long n = this.num * denom + this.denom * num;
      long d = this.denom * denom;
      return new Ratio(n, d);
  }

  // 公開するメソッド
  public double doubleValue() {
      return (double)num / (double)denom;
  }

  public String toString() {
      // 文字列に変換する
      if (denom == 1) {
          return Long.toString(num);
      } else {
          return num + "/" + denom;
      }
  }
  public boolean equals(Object obj) {
// objがthisと等しければtrue，さもなければfalse
      if (obj instanceof Ratio) {
          Ratio r = (Ratio)obj;
          return denom == r.denom && num == r.num;
      } else {
          return false;
      }
  }

  // 分数どうしの加減乗除
  public Ratio add(Ratio r) {
      // thisとrを足した結果のRatioを作って返す
      return add(r.num, r.denom);
  }
  public Ratio subtract(Ratio r) {
      // thisからrを引いた結果のRatioを作って返す
      return add(-r.num, r.denom);          // addを使う．
  }
  public Ratio multiply(Ratio r) {
      // thisとrをかけた結果のRatioを作って返す
      return multiply(r.num, r.denom);
  }
  public Ratio divide(Ratio r) {
      // thisをrで割った結果のRatioを作って返す
      return multiply(r.denom, r.num);          // multiplyを使う．
  }

  // 整数との加減乗除
  public Ratio add(long i) {
      return add(i, 1);
  }
  public Ratio subtract(long i) {
      return add(-i, 1);
  }
  public Ratio multiply(long i) {
      return multiply(i, 1);
  }
  public Ratio divide(long i) {
      return multiply(1, i);
  }
}