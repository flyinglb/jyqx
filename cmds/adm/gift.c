//

int main(object me, string arg)
{
        object *obj, ob;
        if(!arg || arg == "") return notify_fail("��Ҫ��ʲô���\n");
        arg = resolve_path(me->query("cwd"), arg);
        if(file_size(arg) == -1) return notify_fail("û������ļ���\n");
        call_other(arg,"???");
        obj = users();
        for(int i=0;i<sizeof(obj);i++) {
                ob = new(arg);
                ob->set("gift_to_id",obj[i]->query("id"));
                if( !ob->move(obj[i]) ) {
                        destruct(ob);
                        continue;
                }
                tell_object(obj[i],HIY"���϶��������ĵ�����һЩ��������Ŀڴ��� ......\n"NOR);
        }
        return 1;
}
