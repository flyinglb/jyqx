// /u/beyond/mr/shuteng.c
// this is made by beyond
// update 1997.7.2
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",GRN"����"NOR);
         set("long",@long
���ﳤ�������٣�һ֦һ֦������(teng)��ס�����⣬�����̸����,��
ֻ�����������������¡�
long);
         set("item_desc",([
         "teng" : "������ס�����⣬����û��һ����ߣ�ʹ�㼫���Ĳ�����֦(zhi)��\n",
         "zhi" : "���ٵ�֦���Ϻ������˵���ָ���ȥ�ĺۼ���\n",
         ]));
         setup();
}           
 void init()
 {
        add_action("do_move", "pa");
        add_action("do_move", "move");
        add_action("do_leave", "leave");
        add_action("do_leave", "down");                                   
        add_action("do_bo", "bo");    
add_action("do_insert","insert");
add_action("do_insert","shen");
 }                                    
 int do_move(string arg)
{
        object me = this_player();
        if (arg !="down")
        return notify_fail("��Ҫ����������\n");
        if (arg == "down")
        message_vision("$NС�ĵ���ס���٣�������ȥ��\n" , me);
        me->move(__DIR__"hhyuan");
        return 1; 
}                                     
int do_leave(string arg)
{
        object me;
        me = this_player();
        message_vision(HIR "$N�ɿ�˫�֣�����������������׹ȥ�����߷���������\n" NOR, me);
        me->move(__DIR__"hhyuan");
        me->unconcious();
        return 1;
}                                
int do_bo(string arg)
{
        object me;
        me = this_player();
        if (arg !="teng")
        return notify_fail("��Ҫ��ʲô��\n");
        if (arg =="teng")
        message_vision(
                "$N�������٣���ǿ¶��һ˿���⣬��ʱ�㿴��һƬʢ����ӣ�һ���\n",
        me);
        return 1;
}
int do_insert(string arg)
{
        object ob;
        int c_skill;
        int exp;
        ob = this_player();
        exp=(int)ob->query("combat_exp");

        if (arg != "shuteng") return 0;
        c_skill=(int)ob->query_skill("finger", 1);

        if (ob->query("jing")<200)
                return notify_fail("��̫���ˣ��Ѿ�û��������������������ˣ���\n");
        if (c_skill< 200)
                return notify_fail("�����ֲ�����٣������Ѿ��޷������Ļ���ָ���ˡ�\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("jing", 20);
                return notify_fail("��ľ��鲻�����Ѿ��޷������Ļ���ָ���ˡ�\n");
        }

        message_vision("$N��ʱ������ָ������٣����������Щ��΢�Ĵ��ˡ���\n",ob);
        ob->improve_skill("finger", random(100*ob->query_int()));
        ob->receive_damage("jing", 140);
        return 1;
}

