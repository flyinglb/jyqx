#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_shou","shouchong");
	add_action("do_fang","fangchong");
}

void create()
{
	       set_name("��¨", ({"zhu lou" ,"zl"}));
              set_max_encumbrance(30000);
 		set("unit", "��");
		set("long", "����һ��С�ڴ�ǵ���¨��\n");
		set("value", 100);
//            set("no_drop", "�������������뿪�㡣\n");
              set_weight(100);
              set("no_sell",1);
		setup();
}

int do_shou(string arg)
{
    object me,ob1,ob;
    string who,what;
    me = this_player();
//  ob1= this_object();
    if( !arg
	||	sscanf(arg, "%s in %s", who, what)!=2)
         return notify_fail("�����ʽ: shouchong <����> in <��Ʒ>��\n");
    ob1= present(what,me);
    ob = present(who,environment(me));
    if (!ob )
         return notify_fail("��Ҫ��ʲô��\n");
    if (!ob1 )
         return notify_fail("��Ҫ�����յ����\n");
    if(me->query("id")!=(ob->query("host_id"))||ob->query("age")<100)
         return notify_fail(ob->query("name")+"���������㣡\n");
    message_vision("$N����¨������"+ob->query("name")+"���ᴵ��һ�����ڡ�\n",me);
    message_vision("ֻ��"+ob->query("name")+"��������С������һֻ���糤��С�棬�����$N����¨�\n",me);
     ob->move(ob1);
     return 1;
}
int do_fang(string arg)
{
    object me,ob1,ob;
    string who,what;
    me = this_player();
//  ob1= this_object();
    if( !arg
	||	sscanf(arg, "%s from %s", who, what)!=2)
         return notify_fail("�����ʽ: fangchong <����> from <��Ʒ>��\n");
    ob1 = present(what,me);
    if (!ob1)
         return notify_fail("��Ҫ������Ŷ��棿\n");
    ob = present(who,ob1);
    if (!ob )
         return notify_fail("��Ҫ��ʲô��\n");
    if(me->query("id")!=(ob->query("host_id"))||ob->query("age")<100)
         return notify_fail(ob->query("name")+"���������㣡\n");
    tell_object(me,  "�����Ĵ���¨���������"+ob->query("name")+"���˳�����\n" );
 
    message_vision("��Ȼ��һֻ"+ob->query("name")+"��֪��ʲô�ط����˳�����\n",me);
     ob->move(environment(me));
     return 1;
}
