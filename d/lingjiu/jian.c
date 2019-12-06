//room: /d/lingjiu/jian.c

inherit ROOM;

void init();
int do_zou(string);
int do_tiao(string);

void create()
{
  set("short","���ɽ�");
  set("long",@LONG
ɽ������ͻȻ��ʧ��������ǰ��һ��ɽ����ɽ��֮���������ƣ����
���޷�������档һ������(tiesuo)�������У��Ա���һ��ʯ��(bei)��
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "southdown" : __DIR__"yan",
  ]));
  set("objects",([
      __DIR__"npc/yupopo" : 1,
  ]));
  set("item_desc",([
      "bei" : "�����չ����صأ�����������\n" ,
      "tiesuo" : "����ͨ������ġ������š�����Ҳ������߹�(zou)ȥ��\n�������Ṧ���õĻ��������ǲ��ǿ�����(tiao)��ȥ��\n" ,
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
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"xianchou")) )
                room = load_object(__DIR__"xianchou");

        if(!objectp(room))
                return notify_fail("ERROR:not found 'xianchou.c' \n");
        message_vision("$N����������ƮȻ��ȥ��\n",me);
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
                return notify_fail("��̫���ˣ��޷������������ˡ�\n");
        if (c_skill< 200)
                return notify_fail("���Ṧ��Ϊ���������޷����������ݺ���Ծ��\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("qi", 50);
                return notify_fail("��ľ��鲻�����޷�ͨ����Ծ����������ʲô�ˡ�\n");
        }

        message_vision("$N����������������������������أ������������һЩ�Ṧ�ľ��ϡ�\n",ob);
        ob->improve_skill("dodge", random(100*ob->query_int()));
        ob->receive_damage("qi", 100);
        return 1;
}
