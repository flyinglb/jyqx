// /u/beyond/mr/shuteng.c
// this is made by beyond
// update 1997.7.2
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",GRN"密室"NOR);
         set("long",@long
这里桃花岛主一个秘密练功的地方，洞内十分的空阔，
到处都有石块，但不知道有什么作用，墙壁上挂着各种练功
图解。一丝的光线从画外射了进来。
long);
         set("item_desc",([
         "hua" : "画遮住了光线，零零星星有一点光线，使你极力的拨开画(hua)。\n",
         "stone" : "石头上很光华，象是有人练功的痕迹。\n",
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
        return notify_fail("你要往那里掀？\n");
        if (arg == "down")
        message_vision("$N小心地先开画，向外钻去。\n" , me);
        me->move(__DIR__"mushi2");
        return 1; 
}  
int do_leave(string arg)
{
        object me;
        me = this_player();
        message_vision(HIR "$N从画中突然消失。\n" NOR, me);
        me->move(__DIR__"mushi2");
        me->unconcious();
        return 1;
}   
int do_bo(string arg)
{
        object me;
        me = this_player();
        if (arg !="hua")
        return notify_fail("你要干什么？\n");
        if (arg =="hua")
        message_vision(
                "$N拨开画，勉强露出一丝光线。\n",
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
                return notify_fail("你太累了，已经没有力气用手来拍打石头了！！\n");
        if (c_skill< 100)
                return notify_fail("你用拍打石头，但是已经无法提高你的基本手法了。\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("jing", 20);
                return notify_fail("你的经验不够，无法继续领悟什么了。\n");
        }

        message_vision("$N不时地用手拍打石头，似乎感觉自己的手法有所长进。\n",ob);
        ob->improve_skill("hand", random(50*ob->query_int()));
        ob->receive_damage("jing", 30);
        return 1;
}
