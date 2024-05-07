

public class Sort {
    static int partition(int a[], int low , int high)
    {
        int pivot = a[high];
        int i = low -1;
        for(int j = low; j< high; j++){
            if(a[j]<= pivot ){
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        int temp = a[i+1];
        a[i+1] = a[high];
        a[high] = temp;
        return i+1;
    }

    static void qSort(int a[], int low, int high){
        if(low < high){
            int pi = partition(a, low, high);
            qSort(a, low, pi-1);
            qSort(a, pi+1, high);
        }
    }
    public static void main(String[] args) {
        int a[]= {13,2,5,52,12};
        int len = a.length;
        System.out.print("Before Sorting :");
        for(int i =0 ; i<len; i++){
            System.out.print(a[i]+",");
        }
        System.out.println();
        qSort(a,0,len-1);
        System.out.print("After Sorting :");
        for(int i =0 ; i<len; i++){
            System.out.print(a[i]+",");
        }

    }
}
