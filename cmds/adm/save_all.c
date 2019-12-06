int main(object me, string arg)
{
        object *ob;
        int i;
        ob = children(USER_OB);
        i = sizeof(ob);
        write("一共有"+i+"位用户\n");
        while(i--) {
                if( !ob[i]->save() ) write("保存"+ob[i]->query("id")+"数据失败\n");
                else write("保存"+ob[i]->query("id")+"数据成功\n");
        }
        return 1;
}
