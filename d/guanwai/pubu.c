// /guanwai/pubu.c

inherit ROOM;

  int do_longdao();

void create()
{
	set("short", "�����ٲ�");
	set("long", @LONG
���ˮ��������߸߷������䣬����֮��Զ�����ˮ��ֱ����ֹȣ�
����Ȼ������ڡ������ӳ��ǡ�ư������գ�ˮ����������Ĺȵף�����
�ɸߵķ��ˣ�������Ůɢ�������������£�����Ծ��譲�׳��֮��������
ʫ�ƣ����׺����������ģ���ˮ�����������������������ѩ����ͬ��ʹ�
�����������ʯ�ɲ׺���ֱ�ɳ���ʶ�ţ����ʶ��Ȫ����Ȥ�������������
�Ρ���
LONG );
	set("exits", ([
		"southeast"  : __DIR__"damen",
		"westdown"   : __DIR__"xiaotianchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
}
void init()
{
        add_action("do_longdao", "longdao");
}
int do_longdao()
{
object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("blade", 1);
   if (c_skill <20)
   {
     message_vision("$N�Ļ���������Ȼ̫�ͣ��޷���ϰ��\n",ob);
return 1; 
}
c_exp=ob->query("combat_exp");
   if ((c_skill*c_skill*c_skill/10)> c_exp)
{
message_vision("$N��ʵս���鲻�㣬�޷�����\n",ob);
      return 1; 
}
if (ob->query("jing")<20)
{
message_vision("$N̫���ˣ������޷�����\n",ob);
      return 1; 
}
   if (c_skill>100)
{
message_vision("$N�����Լ��Ļ������������Բ������ˡ�\n",ob);
      return 1; 
}

   message_vision("$N������С���������ã��Ի���������������\n",ob);
   ob->improve_skill("blade", random(ob->query("int")) );
   ob->add("jing",-5);
      return 1; 
}
