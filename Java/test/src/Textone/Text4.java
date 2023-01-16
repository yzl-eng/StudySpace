package Textone;

public class Text4 {
    public static void main(String[] args){
        int[] nums={61,23,4,74,13,148,20};
        int max,min,sum,average;
        max=min=nums[0];
        sum=0;
        for(int num:nums){
            if(num>max){
                max=num;
            }
            if(num<min)
            {
                min=num;
            }
            sum=sum+num;
        }
        average=sum/ nums.length;
        System.out.println("max:"+max+" min:"+min+"  sum:"+sum+"  average:"+average);
    }
}
