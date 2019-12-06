inherit ROOM;

void create()
{
        set("short", "�ƺ�ʯ");
        set("long", @LONG
�������һ��˶���ʯͷ���ǰ����ڴ�ѩɽ�������ҵ�����
ʯ�������������ƣ����������ι�״�Ļ��ơ���˵��Ҫ�����ʱ
�򣬻���ɢ������ͬ��״�������������ܣ����ò�ɢ���ǰ���
����ϲ��������ı��
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"meiroad2",
        ]));
        set("item_desc", ([
      "stone" : "���ǿ鲼�����������ƵĴ�ʯ,����������ֻ��һ���������ƺ��ڲ�����ǰ��ӿ��ֱ��������ʯ�ɳ���\n",
        ]));
       set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_think", "think");
}

int do_think()
{
   object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("dodge", 1);
   if (c_skill <150)
   {
      message_vision("$N�Ļ����Ṧ��Ȼ̫�ͣ��޷������ƺ�ʯ���ݡ�\n",ob);
      return 1; 
   }
   c_exp=ob->query("combat_exp");

   if ((c_skill*c_skill*c_skill/10)> c_exp)
   {
      message_vision("$N��ʵս���鲻�㣬�޷������ƺ�ʯ���ݡ�\n",ob);
      return 1; 
   }
   if (ob->query("jing")<20)
   {
      message_vision("$N̫���ˣ������޷������ƺ�ʯ���ݡ�\n",ob);
      return 1; 
   }
   if (c_skill>350)
   {
      message_vision("$N����ʯ������̫��ǳ�ˡ�\n",ob);
      return 1; 
   }

   message_vision("$N������ƺ�ʯ�ϵ���������ڤ˼����.�Ի����Ṧ�����ĵá�\n",ob);  
   ob->improve_skill("dodge", ((int)ob->query("int") + (int)ob->query("dex") + random(10)));
   ob->add("jing",-30);
   return 1;
}

