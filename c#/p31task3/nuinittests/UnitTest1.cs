using NUnit.Framework;
using p31task3;

namespace nuinittests;
public class Tests
{
    DigitUtils digit;
    string filePath1 =
                   System.IO.Path.GetFullPath(@"..\..\..\..\pmp31task3\files\file1.txt");
    string filePath2 =
                   System.IO.Path.GetFullPath(@"..\..\..\..\pmp31task3\files\file2.txt");
    [SetUp]
    public void Setup()
    {
        digit = new DigitUtils();
    }
    [Test]
    public void Test1()
    {
        List<int> expected = new List<int> { 4, 1, 2, 5 };
        List<int> actual = digit.getNumbers(filePath1);
        Assert.AreEqual(expected, actual);
    }
    [Test]
    public void Test2()
    {
        List<int> expected = new List<int> { 5 };
        List<int> actual = digit.getNumbers(filePath2);
        Assert.AreEqual(expected, actual);
    }
}