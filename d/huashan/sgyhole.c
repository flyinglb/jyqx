// Room: /d/huashan/sgyhole.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ���������۵�ɽ�������������ʯ����ȴ��������������������
��ʧ���ľ�����С�������ʯ��(wall)�Ϻܶ�С�ˣ�ȫ�����������ƣ����
��������֮������ʮ�����
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "southup" : __DIR__"zhandao",
            "out"     : __DIR__"sgyhole1",
        ]));
        set("item_desc", ([ 
            "wall" : @TEXT

       o    | o      o    \ o      o      o     <o     <o>
    --^|\    ^|^  --v|^    v|v    |/v   \|X|    \|      |
       /\     >\    /<      >\    /<      >\    /<      >\

       o>     o      o      o      o      o      o      o
       \ __   x     </     <|>    </>    <\>    <)>     |\__
      /<      >\    /<      >\    /<      >\     >>     L
TEXT
        ]));
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
   object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("sword", 1);
   if (c_skill <20)
   {
      message_vision("$N�Ļ���������Ȼ̫�ͣ��޷�����ʯ�����ݡ�\n",ob);
      return 1; 
   }
   c_exp=ob->query("combat_exp");

   if ((c_skill*c_skill*c_skill/10)> c_exp)
   {
      message_vision("$N��ʵս���鲻�㣬�޷�����ʯ�����ݡ�\n",ob);
      return 1; 
   }
   if (ob->query("jing")<20)
   {
      message_vision("$N̫���ˣ������޷�����ʯ�����ݡ�\n",ob);
      return 1; 
   }
   if (c_skill>101)
   {
      message_vision("$N����ʯ������̫��ǳ�ˡ�\n",ob);
      return 1; 
   }

   message_vision("$N�����ʯ��������˼�����ã��Ի���������������\n",ob);
   ob->improve_skill("sword", random(10*ob->query("int")));
   ob->add("jing",-5);
   return 1;
}

