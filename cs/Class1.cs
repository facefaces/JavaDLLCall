namespace ClassLibrary1
{
    public class Class1
    {
        private int BaudRate = 8000;
        private string Name = "initial";

        public int AddBaudRate(int a)
        {
            return BaudRate + a;
        }

        public string SetName(string name)
        {
            Name = name;
            return Name;
        }

        public string GetName()
        {
            return Name;
        }
    }
}