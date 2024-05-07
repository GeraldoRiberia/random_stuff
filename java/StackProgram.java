class Stack{
    int top;
    Stack(){
        this.top = -1;
    }
    int stk[] = new int[100];
    void push(int item){
        if(top >= 100){
            System.out.println("Stack overflow ");
        }
        else{
            stk[++top] = item;
        }
    }

    void pop(){
        if(top == -1){
            System.out.println("Stack underflow");
        }
        else{
            System.out.println("Item popped : "+stk[top--]);
        }
    }
    void display(){
        if(top == -1){
            System.out.println("Stack Underflow");
        }
        else{
            for(int i =0; i <= top; i++){
                System.out.println(stk[i]);
            }
        }
    }
}

public class StackProgram {
    public static void main(String[] args) {
        Stack s1 = new Stack();
        s1.push(12);
        s1.push(512);
        s1.display();
        s1.pop();
        s1.display();
        s1.pop();
        s1.pop();
    }
}
