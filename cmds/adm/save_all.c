int main(object me, string arg)
{
        object *ob;
        int i;
        ob = children(USER_OB);
        i = sizeof(ob);
        write("һ����"+i+"λ�û�\n");
        while(i--) {
                if( !ob[i]->save() ) write("����"+ob[i]->query("id")+"����ʧ��\n");
                else write("����"+ob[i]->query("id")+"���ݳɹ�\n");
        }
        return 1;
}
