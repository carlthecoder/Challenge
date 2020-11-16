using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WarsConsole
{
    public static class CodeWars
    {
        public static int[] ArrayDiff(int[] a, int[] b)
        {
            // My Solution:

            //var list = a.ToList();
            //foreach (var elem in b)
            //{
            //    list.RemoveAll(x => x == elem);                
            //}
            //return list.ToArray();

            // Clever Solution:

            return a.Where(elem => !b.Contains(elem)).ToArray();
        }

        public static IEnumerable<T> UniqueInOrder<T>(IEnumerable<T> iterable)
        {
            // My Solution:

            //List<T> returnList = new List<T>();
            //var it = iterable.GetEnumerator();
            //if (it.MoveNext())
            //{
            //    var current = it.Current;
            //    returnList.Add(current);

            //    while (it.MoveNext())
            //    {
            //        if (current.Equals(it.Current))
            //            continue;
            //        current = it.Current;
            //        returnList.Add(current);
            //    }
            //}
            //return returnList;

            // Clever Solution:

            T previous = default(T);
            foreach (T current in iterable)
            {
                if (!current.Equals(previous))
                {
                    previous = current;
                    yield return current;
                }
            }
        }
    }
}
