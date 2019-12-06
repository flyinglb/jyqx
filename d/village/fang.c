//write by tiandi 1999.10.9
inherit ROOM;
void create()
{
    set("short","采茶室");
    set("long", @LONG
这里是一间采茶室, 里面灯光黑暗,但是堆满了村民们采回来的茶叶, 叶子还没有
经过检采, 你看着看看,不禁想自已也来试试这村民们检茶的乐趣.
LONG);
    set("exits", ([
        "east" : "/d/village/sroad4.c",
    ]));
    set("no_clean_up",0);
    setup();
}

void init()
{
    add_action("do_cai", "cai");
}

int do_cai()
{
     object me;
    int qi_cost,c_exp,c_skill;
    me = this_player();
    c_exp=me->query("combat_exp");
    c_skill=me->query_skill("hand",1);
    write("你卷起袖子, 两手向茶叶盘里一伸,在昏暗的灯光下开始采茶. \n");
  qi_cost =10;
    if (me->query("qi")>qi_cost);
      {
        if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
        me->improve_skill("hand", (int)me->query_skill("hand", 1));
        me->receive_damage("qi", qi_cost );
      }
      return 1;
}


