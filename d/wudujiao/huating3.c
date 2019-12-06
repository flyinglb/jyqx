// by mayue

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
������һ����԰�е�Сͤ�ӣ�������������ɫ���㡣���Ϲ���һ������Ů
�����轣ͼ��(picture)��
LONG
	);
//     set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"huating",
		"south" : __DIR__"huating1",
		"west" : __DIR__"huayuan3",
//		"north" : __DIR__"huating3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
       set("item_desc",([
         "picture":"ֻ��������Ů�ֳָֹ�����Ц��������㱼����ƺ��������������������������\n�������ƺ�������ĳ�ְ��أ���������Ż��е����ƱȻ�(bihua)һ�¿���\n\n",
]));
	setup();
//	replace_program(ROOM);
}

void init()
{
  add_action("do_bihua", "bihua");
}

int do_bihua(string arg)
{
  object weapon;
  object me=this_player();
  int swordskill=(int)me->query_skill("sword", 1);
//  int maxlevel, exp=(int)me->query("combat_exp");
  int exp=(int)me->query("combat_exp");
 
  if( !arg || arg != "picture")
    return notify_fail("���ұȻ�ʲô��\n");
  if( me->query("qi") < (int)(me->query("max_qi")/5))
    return notify_fail("������ȥ��������ģ�\n");
  if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("���ù������ұȻ�ʲô��\n");
//  if (!((string)me->query("family/family_name")=="�嶾��"))
//    {
//      message_vision("$N���ű��ϵĻ����˼��Σ�����һ�������\n", me);
//    }
  else
    {
      message_vision("$N�����������ջ�����Ů����������һ�ˡ�\n", me);
      if (exp*10 <= (swordskill*swordskill*swordskill))
	{
	  me->receive_damage("qi", 30);
	  return notify_fail("��ľ��鲻�����Ѿ����ܴӻ�������ʲô�ˡ�\n");
	}
      if (swordskill<(int)me->query_skill("dodge",1))
	{
          me->improve_skill("sword", random(5 * (int)(me->query_int()
                          +me->query_skill("sword") * 4)));
	  tell_object(me, "����������һЩ����������������š�\n");
	}
      else
	{
	  tell_object(me, "����˰��쾢������ʲôҲû��ѧ����\n");
	}
    }
  me->receive_damage("qi", 50);
  return 1;
}

