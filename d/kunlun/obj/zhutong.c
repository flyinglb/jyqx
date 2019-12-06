// ��Ͳ

inherit ITEM;

varargs int destruct_she(object obj, object me, int f);
string disply_long();

void create()
{
        set_name("��Ͳ", ({"zhu tong", "tong"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",(: disply_long :));
                set("unit", "��");
        }
}

void init()
{
        if(environment()!=this_player()) return;
        add_action("do_get","get");
        add_action("do_put","put");
}

int do_put(string arg)
{
        string item, in_where;
        object obj, me;
        if( !arg || sscanf(arg,"%s in %s",item,in_where)!=2 ) return 0;//����ֽ�
        if( item != "jinshe" && item != "yinshe" ) return 0;//������Ƿ��߷��� 0
        if( in_where != "zhu tong" && in_where != "tong" ) return 0;//������Ƿŵ���Ͳ���� 0
        me = this_player();
        if( !obj = present(item,me) )//����߲�������
                obj = present(item,environment(me));//���ڻ�������
        if( !obj ) return notify_fail("��Ҫ��ʲô��\n");//���û���ҵ�����
        if( query("have_she/"+item) ) //�����Ͳ���Ѿ�����
                return destruct_she(obj,me);//�ƻ�����

        //�����жϽ�������ʼ����
        set("have_she/"+item,1);//�����߱��
        message_vision("$N��"+obj->name()+"�Ž�����Ͳ�\n",me);
        return destruct_she(obj,me,1);//�ƻ�����
}

int do_get(string arg)
{
        string item, from;
        object obj, me;
        if( !arg || sscanf(arg,"%s from %s",item,from)!=2 ) return 0;//����ֽ�
        if( item != "jinshe" && item != "yinshe" ) return 0;//������Ƿ��߷��� 0
        if( from != "zhu tong" && from != "tong" ) return 0;//������Ƿŵ���Ͳ���� 0
        if( !query("have_she/"+item) ) //�����Ͳ��û�����߱��
                        return notify_fail("��Ҫ��ʲô��\n");
        //�����жϽ�������ʼ����
        obj = new(__DIR__+item);//�������
        me = this_player();
        obj->move(environment(me));
        delete("have_she/"+item);//ɾ�����߱��

        message_vision("$N��"+obj->name()+"����Ͳ�����˳�����\n",me);
        return 1;
}

varargs int destruct_she(object obj, object me, int f)
{
        if( !f ) {
                message_vision("$N��"+obj->name()+"�Ž�����Ͳ�\n"
                +"ֻ������һ��ȥ����ҧһͨ����һ��Ͳ����߾Ͷ����ˡ�\n",me);
                delete("have_she");//ɾ�����߱��
        }
        obj->move(VOID_OB);
        destruct(obj);
        return 1;
}

string disply_long()
{
        string str = "���Ǹ����������ɵ���Ͳ��\n";
        if( !query("have_she/jinshe") && !query("have_she/yinshe"))
                str += "�������ǿյġ�\n";
        else {
                str += "�������У�";
                if( query("have_she/jinshe") > 0)
                        str += "\tһ��"+HIY+"��ɫѪ��\n"+NOR;
                if( query("have_she/yinshe") > 0)
                        str += "\tһ��"+HIW+"��ɫѪ��\n"+NOR;
                str +="\n";
        }
        return str;
}
