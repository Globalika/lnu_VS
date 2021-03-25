using HDF.PInvoke;
using System;
using System.Diagnostics;
using System.IO;

using hid_t = System.Int32;
using herr_t = System.Int64;
using hsize_t = System.UInt64;

namespace task2
{
    class Program
    {
        static (int[,], int, int) GetMatrixFromFile(string filePath)
        {
            char delim = ' ';
            int[,] matrix;
            int rows, columns;
            using (var streamReader = new StreamReader(filePath))
            {
                string fileLine, dimensionLine;
                dimensionLine = streamReader.ReadLine();
                string[] dimensions = dimensionLine.Split(delim);
                rows = int.Parse(dimensions[0]);
                columns = int.Parse(dimensions[1]);
                //
                matrix = new int[rows, columns];
                for (int i = 0; i < rows; i++)
                {
                    fileLine = streamReader.ReadLine();
                    string[] strObjItems = fileLine.Split(delim);
                    for (int j = 0; j < columns; j++)
                    {
                        matrix[i, j] = int.Parse(strObjItems[j]);
                    }
                }
            }
            return (matrix, rows, columns);
        }
        static void PrintRectangularMatrix(
            (int[,] matrix, int rows, int columns) tuple, string str)
        {
            Console.WriteLine($"Rectangular Matrix {str}:");
            for (int i = 0; i < tuple.rows; i++)
            {
                for (int j = 0; j < tuple.columns; j++)
                {
                    Console.Write($"{tuple.matrix[i, j]} ");
                }
                Console.WriteLine();
            }
        }
        static (int[][], int, int) TransformMatrixToJaggedOne(
            (int[,] matrix, int rows, int columns) tuple)
        {
            int[][] jaggedMatrix = new int[tuple.rows][];
            for (int k = 0; k < tuple.rows; k++)
            {
                jaggedMatrix[k] = new int[tuple.columns];
            }
            for (int i = 0; i < tuple.rows; i++)
            {
                for (int j = 0; j < tuple.columns; j++)
                {
                    jaggedMatrix[i][j] = tuple.matrix[i, j];
                }
            }
            return (jaggedMatrix, tuple.rows, tuple.columns);
        }
        static void PrintJaggedMatrix(
            (int[][] matrix, int rows, int columns) tuple, string str)
        {
            Console.WriteLine($"Jagged Matrix {str}");
            for (int i = 0; i < tuple.rows; i++)
            {
                for (int j = 0; j < tuple.matrix[i].Length; j++)//tuple.columns
                {
                    Console.Write($"{tuple.matrix[i][j]} ");
                }
                Console.WriteLine();
            }
        }
        static (int[,], int, int) MultiplyRectangularMatrixies(
            (int[,] matrix, int rows, int columns) tuple1,
            (int[,] matrix, int rows, int columns) tuple2)
        {
            Stopwatch stopWatchRectangular = new Stopwatch();
            stopWatchRectangular.Start();

            int[,] resultMatrix = new int[tuple1.rows, tuple2.columns];
            for (int i = 0; i < tuple1.rows; i++)
            {
                for (int j = 0; j < tuple2.columns; j++)
                {
                    resultMatrix[i, j] = 0;
                    for (int k = 0; k < tuple1.columns; k++)
                    {
                        resultMatrix[i, j] += tuple1.matrix[i, k] * tuple2.matrix[k, j];
                    }
                }
            }
            stopWatchRectangular.Stop();
            Console.WriteLine($"Rectangular Matrixies Multiply Time: {stopWatchRectangular.Elapsed}");
            return (resultMatrix, tuple1.rows, tuple2.columns);
        }
        static (int[][], int, int) MultiplyJaggedMatrixies(
            (int[][] matrix, int rows, int columns) tuple1,
            (int[][] matrix, int rows, int columns) tuple2)
        {
            Stopwatch stopJaggedWatch = new Stopwatch();
            stopJaggedWatch.Start();
            int[][] resultMatrix = new int[tuple1.rows][];
            for (int k = 0; k < tuple1.rows; k++)
            {
                resultMatrix[k] = new int[tuple2.columns];
            }

            for (int i = 0; i < tuple1.rows; i++)
            {
                for (int j = 0; j < tuple2.columns; j++)
                {
                    resultMatrix[i][j] = 0;
                    for (int k = 0; k < tuple1.columns; k++)
                    {
                        resultMatrix[i][j] += tuple1.matrix[i][k] * tuple2.matrix[k][j];
                    }
                }
            }
            stopJaggedWatch.Stop();
            Console.WriteLine($"Jagged Matrixies Multiply Time: {stopJaggedWatch.Elapsed}");
            return (resultMatrix, tuple1.rows, tuple2.columns);
        }
        static void SaveRectangularMatrixToHDF5File((int[,] matrix, int rows, int columns) tuple)
        {
            Console.WriteLine("h5 file creating..\n");
            IntPtr ptr;
            herr_t status, file_id, dataspace_id, dataset_id;
            //
            hsize_t rows = (hsize_t)tuple.rows, columns = (hsize_t)tuple.columns;
            hid_t[,] data = new hid_t[tuple.rows, tuple.columns];
            //
            for (hsize_t i = 0; i < rows; i++)
            {
                for (hsize_t j = 0; j < columns; j++)
                {
                    data[i, j] = tuple.matrix[i, j];
                }
            }
            unsafe
            {
                fixed (int* parr = data)
                {
                    ptr = new IntPtr(parr);
                }
            }
            //
            hsize_t[] dims = { rows, columns };
            var maxdims = dims;
            string h5FilePath = "C:/Users/volod/source/Lnu_VS/c#/task2/task2/file/matrix.h5";
            file_id = H5F.create(h5FilePath, H5F.ACC_TRUNC);
            dataspace_id = H5S.create_simple(2, dims, null);
            dataset_id = H5D.create(file_id, "/dset", H5T.STD_I32BE, dataspace_id,
                                    H5P.DEFAULT);
            status = H5D.write(dataset_id, H5T.NATIVE_INT, H5S.ALL, H5S.ALL,
                               H5P.DEFAULT, ptr);
            status = H5D.close(dataset_id);
            status = H5F.close(file_id);
            Console.WriteLine("File has been succsessfully created! Matrix has been written!" +
                $"\nPath: {h5FilePath}\n");
            return;
        }
        static void Main(string[] args)
        {
            string filePathA = @"C:\Users\volod\source\Lnu_VS\c#\task2\task2\file\matrixA.txt";
            string filePathB = @"C:\Users\volod\source\Lnu_VS\c#\task2\task2\file\matrixB.txt";
            Console.WriteLine();
            var rectangularMatrixA = GetMatrixFromFile(filePathA);
            var rectangularMatrixB = GetMatrixFromFile(filePathB);
            PrintRectangularMatrix(rectangularMatrixA, "A");
            PrintRectangularMatrix(rectangularMatrixB, "B");
            Console.WriteLine();
            var jaggedMatrixA = TransformMatrixToJaggedOne(rectangularMatrixA);
            var jaggedMatrixB = TransformMatrixToJaggedOne(rectangularMatrixB);
            PrintJaggedMatrix(jaggedMatrixA, "A");
            PrintJaggedMatrix(jaggedMatrixB, "B");
            Console.WriteLine();
            var resultByMultiplyRectangularMatrixies = MultiplyRectangularMatrixies(
                rectangularMatrixA, rectangularMatrixB);
            PrintRectangularMatrix(resultByMultiplyRectangularMatrixies, "A*B");
            var resultByMultiplyJaggedMatrixies = MultiplyJaggedMatrixies(
                jaggedMatrixA, jaggedMatrixB);
            PrintJaggedMatrix(resultByMultiplyJaggedMatrixies, "A*B");
            //
            Console.WriteLine();
            SaveRectangularMatrixToHDF5File(resultByMultiplyRectangularMatrixies);
            //
            Console.ReadLine();
        }
    }
}