     #include<stdio.h>
  	 #include<malloc.h>
  	 #include<memory.h>
  	 typedef struct sbuff_{
  	     int * buff;
  	     int start;
 	     int end;
  	     int size;
  	     int count;

  	 } sbuff_t;
  	 sbuff_t * sbuff_new(int size)
  	 {
  	   sbuff_t * sb = (sbuff_t*)malloc(sizeof(sbuff_t));
  	   memset(sb, 0, sizeof(sbuff_t));
  	   sb->size = size;
  	     sb->buff = (int*)malloc(sizeof(int)*size);
  	   return sb;
  	 }
  	 void sbuff_add(sbuff_t * sb, int elem)
  	 {
  	   int end = sb->end;
  	   if(sb->count && (end % sb->size) == sb->start){
  	     printf("Overflow Elem[%d] %d lost\n", sb->start, sb->buff[sb->start]);
  	     sb->start = (sb->start + 1 ) %sb->size;
  	     sb->count --;
  	   }
  	   printf("Added Elem[%d] = %d\n",sb->end, elem);
  	   sb->buff[sb->end] = elem;
  	   sb->end = (sb->end+1) % sb->size;
  	   sb->count ++;
  	   }
  	 }
  	 int sbuff_remove(sbuff_t * sb)
  	 {
  	   int start = sb->start ;
  	   int ret = -1;
  	   if(sb->count <= 0) {
  	     printf("Buffer is empty\n");
  	     return ret;
  	   }
  	   if(sb->count || (start % sb->size) != sb->end) {
  	     printf("Removed Elem[%d] = %d\n",sb->start, sb->buff[sb->start]);
  	     ret = sb->buff[sb->start];
  	     sb->start = (sb->start + 1 ) % sb->size;
  	     sb->count--;
  	   } else {
  	     printf("Buffer is empty\n");
  	   }
  	   return ret;
  	 }
  	 void sbuff_print(sbuff_t * sb)
  	 {
  	   int start = sb->start ;
  	   int end = sb->end ;
  	   int i, count = 0;
  	   for(i = start; count < sb->count; i = (i + 1)%sb->size){
 	     printf("Elem[%d] = %d\n", i, sb->buff[i]);
  	     count++;
  	     if(i == (end - 1)) {
  	       break;
  	     }
  	   }
  	 }
  	 void sbuff_delete(sbuff_t * sb)
  	 {
  	   free(sb->buff);
  	   free(sb);
  	 }
  	 int main(int argc, char *argv[])
 	 {
  	   char key;
  	   int elem;
  	   sbuff_t * sb = sbuff_new(5);
  	   while(1) {
  	     printf("circular buffer add[a], remove[r], print[p] : ");
  	     fflush(stdin);
  	     key = getchar();
  	     switch(key){
  	       case 'a':
  	       {
  	         printf("Element to add : ");
  	         scanf("%d", &elem);
  	         sbuff_add(sb, elem);
          break;
  	       }
  	       case 'r':
  	       {
  	         sbuff_remove(sb);
  	         break;
  	       }
  	       case 'p':
  	       {
  	         sbuff_print(sb);
  	         break;
  	       }
  	       default:
  	       {
 	         sbuff_delete(sb);
  	         exit(0);
 	       }
 	     }
  	   }
  	   return 0;
  	 }
