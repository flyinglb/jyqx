// /u/beyond/mr/shuteng.c
// this is made by beyond
// update 1997.7.2
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",GRN"����"NOR);
         set("long",@long
�����һ�����һ�����������ĵط�������ʮ�ֵĿ�����
��������ʯ�飬����֪����ʲô���ã�ǽ���Ϲ��Ÿ�������
ͼ�⡣һ˿�Ĺ��ߴӻ������˽�����
long);
         set("item_desc",([
         "hua" : "����ס�˹��ߣ�����������һ����ߣ�ʹ�㼫���Ĳ�����(hua)��\n",
         "stone" : "ʯͷ�Ϻܹ⻪���������������ĺۼ���\n",
         ]));
         setup();
}
 void init()
 {
        add_action("do_move", "xian");
        add_action("do_move", "move");
        add_action("do_leave", "leave");
        add_action("do_leave", "zuan");   
        add_action("do_bo", "bo"); 
add_action("do_insert","insert");
add_action("do_insert","hand");
 } 
 int do_move(string arg)
{
        object me = this_player();
        if (arg !="down")
        return notify_fail("��Ҫ�������ƣ�\n");
        if (arg == "down")
        message_vision("$NС�ĵ��ȿ�����������ȥ��\n" , me);
        me->move(__DIR__"mushi2");
        return 1; 
}  
int do_leave(string arg)
{
        object me;
        me = this_player();
        message_vision(HIR "$N�ӻ���ͻȻ��ʧ��\n" NOR, me);
        me->move(__DIR__"mushi2");
        me->unconcious();
        return 1;
}   
int do_bo(string arg)
{
        object me;
        me = this_player();
        if (arg !="hua")
        return notify_fail("��Ҫ��ʲô��\n");
        if (arg =="hua")
        message_vision(
                "$N����������ǿ¶��һ˿���ߡ�\n",
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

        if (arg != "stone") return 0;
        c_skill=(int)ob->query_skill("hand", 1);

        if (ob->query("jing")<50)
                return notify_fail("��̫���ˣ��Ѿ�û�������������Ĵ�ʯͷ�ˣ���\n");
        if (c_skill< 100)
                return notify_fail("�����Ĵ�ʯͷ�������Ѿ��޷������Ļ����ַ��ˡ�\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("jing", 20);
                return notify_fail("��ľ��鲻�����޷���������ʲô�ˡ�\n");
        }

        message_vision("$N��ʱ�������Ĵ�ʯͷ���ƺ��о��Լ����ַ�����������\n",ob);
        ob->improve_skill("hand", random(50*ob->query_int()));
        ob->receive_damage("jing", 30);
        return 1;
}
