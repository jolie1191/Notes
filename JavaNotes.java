import java.util.Random;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");

        /*
        
            String scanner.next();
            int scanner.nextInt();
        * */

//        Scanner scanner = new Scanner(System.in);
//        String i = scanner.next();
//        System.out.println(i);

        Random random = new Random();
        int i = random.nextInt(100);
        System.out.println(i);

        int[] arr0 = new int[3];
        int[] arr = new int[]{1,2 ,3};
        int[] arr1 = {1, 2, 3};

        int[][] arr2 = new int[2][3];
        int[][] arr3 = new int[][]{{1,2,3}};
        System.out.println(arr);




        /*
        * 方法调用参数：
        * 1. 参数是基本类型： 传递是值传递，另一个方法改变值不影响主方法
        * 2. 参数是引用类型： 传递引用， 会改变外面的值 */

        /*引用数据类型是无限的：
        * 1. 类： 是引用数据类型
        * 2. ArrayList数组集合， ArrayList只储存引用数据类型， 不能存储基本数据类型（可以吧基本类型转成引用类型：int -->Integer
        * 3. 接口*/

        /*常见ASCII表
        * 1. 0- 9： 48-57
        * 2. A-Z： 65-90
        * 3.a-z: 97-122 */

        char a = 'a';
        int b = a + 1;

        int c = 90;
        char d = (char) c;

        /*接口 interface：
        * 1. 特殊类型的抽象类： 里面全部是抽象方法
        * 2. 接口中的成员变量已经全是"常量"， 永不可改变
        * 3. 类是implements接口
        * 4. 一个类可以implements多个接口*/

        /*含有static的变量可以直接被类名/接口名直接调用, 而不用new对象
        * 1. MyInterface.x
        * 2. Employee.x*/

        /*接口和抽象类的区别
        * 1. 抽象类是某个对象含有的基本功能
        * 2. 有些对象如：缉毒狗，还含有特殊的"缉毒"功能， 那么"缉毒"功能定义在接口中*/

        /*1. 抽象类是这个事物应该具备的功能
        * 2. 接口定义了这个事物额外的功能*/

        /*多态的三种调用方式
        * 1. 父类类型/接口类型 变量 = new 子类对象（）
        * 2. 变量名.show()
        * 3. 多态的调用方法必须运行子类的重写
        * 多态调用方式： 普通调用（继承）， 抽象类调用， 接口调用
        * 多态： 继承，方法重写*/

        /*引用类型的变量之间的比较用instanceof*/

        /*Person student = new Student()
        * student.sleep()
        * 注意： 此处sleep（）是Person和Student的共有方法
        * student滴啊用sleep（）方法， 运行子类重写
        * 此处的student不能调用子类playGame（）的特有功能*/

        /*面向对象：
        * 1. 封装： encapsulate 属性 & 方法 of object， hide details of object， and provide interface/function to pubic
        * 2. 继承: subclass inherit all attributes and functions of Parent
        * 3. 多态: use Inheritance and Function Override to make code more reusable and scalable */


        /*
        * static:（共享数据）
        * 所有对象的共享数据，避免资源浪费
        * 1. 背static修饰的成员变量，可以直接被类名调用，反正结果也一样
        * 2. static 变量/方法处于内存中的（JVM静态区）
        * 3. 如果有某个对象对静态变量进行修改，其他对象access这个静态变量也随之修改
        * 4. static生命周期先于非静态变量/ 方法（记忆： static 是先人，非静态是 后人）
        * 5. static的应用场景：
        *  - static可修饰成员变量，方法
        *  - 当定义一个事物时，考虑多个事物之间是否有共性的数据！！！-- 共性数据可定义为static
        *  - static方法，跟着static成员变量走且没有调用非静态成员（记忆，方法里调用的权威static变量，则定义方法为静态）
        *
        * example：USC的学生：
        * 1. Student:
        * - String name
        * - int age
        * - 然而schoolName都一样，所以可以定义为static，为共享数据
        *
        * 总结：
        * 1.对象的特有属性：名字，age （非静态修饰）
        * 2. 对象的共享属性： 学校名 （静态修饰）
        * */

        /*定义常量：（变量名全大写）
        * - public static final COMPANY_NAME = "Google";
        * */


        /*创建一个匿名对象
        * 1. new Person（）；*/

        /*内部类（一个对象形成还可以包含另一个独立类
        * 1. */
    }
}
