//room: /d/lingjiu/jian.c

inherit ROOM;

void init();
int do_zou(string);
int do_tiao(string);

void create()
{
  set("short","百丈涧");
  set("long",@LONG
山道到此突然消失，在你面前是一条山涧，山涧之中云雾缭绕，你根
本无法看清对面。一条铁索(tiesuo)深入云中，旁边有一块石碑(bei)。
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "southdown" : __DIR__"yan",
  ]));
  set("objects",([
      __DIR__"npc/yupopo" : 1,
  ]));
  set("item_desc",([
      "bei" : "『灵鹫宫』重地，擅入者死！\n" ,
      "tiesuo" : "这是通往对面的“接天桥”，你也许可以走过(zou)去。\n不过你轻功够好的话，看看是不是可以跳(tiao)上去。\n" ,
  ]));
  setup();
}

void init()
{
        add_action("do_zou", "zou");
        add_action("do_tiao","tiao");
}

int do_zou(string arg)
{
        object me=this_player(), room;

        if(!arg || arg!="tiesuo")
                return notify_fail("你要走什么？\n");

        if(!( room = find_object(__DIR__"xianchou")) )
                room = load_object(__DIR__"xianchou");

        if(!objectp(room))
                return notify_fail("ERROR:not found 'xianchou.c' \n");
        message_vision("$N踩上铁索，飘然而去。\n",me);
        me->move(room);
        return 1;
}

int do_tiao(string arg)
{
        object ob;
        int c_skill;
        int exp;
        ob = this_player();
        exp=(int)ob->query("combat_exp");


        if (arg != "tiesuo") return 0;
        c_skill=(int)ob->query_skill("dodge", 1);

        if (ob->query("qi")<120)
                return notify_fail("你太累了，无法再跳上铁索了。\n");
        if (c_skill< 200)
                return notify_fail("你轻功修为还不够，无法在铁索上纵横跳跃。\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("qi", 50);
                return notify_fail("你的经验不够，无法通过跳跃铁索来领悟什么了。\n");
        }

        message_vision("$N纵身而起，跳到铁索上往返几个来回，从中领悟出了一些轻功的诀窍。\n",ob);
        ob->improve_skill("dodge", random(100*ob->query_int()));
        ob->receive_damage("qi", 100);
        return 1;
}
