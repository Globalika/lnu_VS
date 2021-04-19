using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace MyWikipediaTask3.DataBase.Impl
{
    public class BinaryDataBase : BaseDataBase
    {
        public string GetStringFromReader(BinaryReader br, string type)
        {
            if (type == "int")
            {
                return br.ReadInt32().ToString();
            }
            else if (type == "string")
            {
                return br.ReadString();
            }
            else
            {
                throw new Exception();
            }
        }
        public void WriteItemToFile(BinaryWriter bw, string type, string elem)
        {
            if (type == "int")
            {
                bw.Write(int.Parse(elem));
            }
            else if (type == "string")
            {
                bw.Write(elem);
            }
            else
            {
                throw new Exception();
            }



        }
        public override List<string[]> GetTableContent(string tableName)
        {
            List<string[]> list = new List<string[]>();
            FileStream fs = new FileStream(CreateTablePath(tableName), FileMode.Open);
            BinaryReader br = new BinaryReader(fs, Encoding.UTF8);
            try
            {
                int SIZE = br.ReadInt32();
                string[] metaData = new string[SIZE+1];
                metaData[0] = SIZE.ToString();
                for(int i = 1; i < SIZE+1; i++)
                {
                   metaData[i] = br.ReadString();
                }
                //
                while (true)//br.PeekChar() > -1
                {
                    string[] str =  new string[SIZE];
                    for (int i = 0; i < SIZE; i++)
                    {
                        str[i] = GetStringFromReader(br, metaData[i+1]);
                    }
                    list.Add(str);
                }
            }
            catch (Exception ex)
            {

            }
            finally
            {
                br.Close();
                fs.Close();
            }
            return list;
        }

        public override void UpdateTableContent(List<string[]> list, string tableName, string[] metaData)////
        {
            FileStream fs = new FileStream(CreateTablePath(tableName), FileMode.Create);
            BinaryWriter bw = new BinaryWriter(fs, Encoding.UTF8);
            bw.Write(int.Parse(metaData[0]));
            for (int i = 1; i < metaData.Length; i++)
            {
                bw.Write(metaData[i]);
            }
            foreach (var it in list)
            {
                for (int i = 0; i < int.Parse(metaData[0]); i++)
                {
                    WriteItemToFile(bw,metaData[i+1],it[i]);
                    //bw.Write(it[i]);
                }
            }
            bw.Close();
            fs.Close();
        }

    }
}