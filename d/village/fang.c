//write by tiandi 1999.10.9
inherit ROOM;
void create()
{
    set("short","�ɲ���");
    set("long", @LONG
������һ��ɲ���, ����ƹ�ڰ�,���Ƕ����˴����ǲɻ����Ĳ�Ҷ, Ҷ�ӻ�û��
�������, �㿴�ſ���,����������Ҳ������������Ǽ�����Ȥ.
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
    write("���������, �������Ҷ����һ��,�ڻ谵�ĵƹ��¿�ʼ�ɲ�. \n");
  qi_cost =10;
    if (me->query("qi")>qi_cost);
      {
        if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
        me->improve_skill("hand", (int)me->query_skill("hand", 1));
        me->receive_damage("qi", qi_cost );
      }
      return 1;
}


