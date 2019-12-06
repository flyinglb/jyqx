// dongnei.c
// this is made by beyond
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short","洞内");
        set("long",@long
这里少林一个秘密的地方，洞内十分的空阔，到处都有机
关人(jiguan ren)但不知道有什么作用，零零星星的只有几个
少林弟子在这里练功，旁边还有几个少林弟子在打坐吐纳。旁
边还有一个巨大的石头把来时的洞口堵的严严的。
long);
        set("item_desc", ([

 "jiguan ren" : "这是按照人形做的，活生生的，但不知道有什么作用。\n",
        ]));

        setup();
}

void init()
{
        add_action("do_break","break");
        add_action("do_study", "bihua");
        add_action("do_study", "duilian");
}

int do_study(string arg)
{
        object ob;
        int c_skill;
        int exp;
        ob = this_player();
        exp=(int)ob->query("combat_exp");

        if (arg != "jiguan ren") return 0;
        c_skill=(int)ob->query_skill("unarmed", 1);

        if (ob->query("jing")<100)
                return notify_fail("你太累了，已经没有力气来和机关人对练的了！\n");
        if (c_skill< 200)
                return notify_fail("你与机关人对练了一会，感觉与机关人对练，领悟不到什么了。\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("jing", 50);
                return notify_fail("你的经验不够，无法继续领悟什么了。\n");
        }

        message_vision("$N与机关人对练了一会，似乎感觉自己的基本拳脚有点长进。\n",ob);
        ob->improve_skill("unarmed", random(100*ob->query_int()));
        ob->receive_damage("jing", 70);
        return 1;
}

 int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="stone" ) {
                write("你要打碎什么的东西！\n");
                return 1;
        }

  message_vision(
   "$N深吸一口气，双掌同时拍出。\n", this_player());

  if (n>=500) {
        message_vision(
 "$N只听一声“轰”的一声，$N把岩石震开了！一个向上的洞口出现在你面前。\n", this_player());
        set("exits/out", __DIR__"linnei");
        this_player()->set("neili",n-500);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",10);
           }

        return 1;
    }

     void close(object room)
    {
message("vision","岩石滚回了原位，又挡住了洞口。\n", room);
         room->delete("exits/up");
   }



