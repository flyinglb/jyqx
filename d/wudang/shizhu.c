//Room: shizhu.c ʯ��
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ʯ��");
      set("long",@LONG
�������ҹ�ǰ��һ��ʯ����������Σ����ͱ��Ϻ��������������졣����
��һ��¯���ڴ������Ϊ������ͷ�㡱������͵������Ը��ʯ��������������
���޷�����ǰ�а������ƣ�����������Ԩ����һʧ�㣬��ʬ���޴档
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northup"  : __DIR__"nanyanfeng",
          "enter"    : __DIR__"nanyangong",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
}

void init()
{
        add_action("do_mianbi", "face");
}


int do_mianbi(string arg)
{
   object ob;

   ob = this_player();
   if ( !arg )
   {
      message_vision("$N�����ʯ��������˼���ã���æһ����һ������\n",ob);
      return 1;
   }
   if ((int)ob->query_skill("taoism", 1) <100)
   {
      message_vision("$N�����ʯ������������ģ�ûһ������ʶ��\n",ob);
      return 1;
   }
   if ((int)ob->query_skill("literate", 1) <100)
   {
      message_vision("$N��ʯ����ÿһ���ֶ���ʶ�����ǲ�֪��˵����ʲô��\n",ob);
      return 1;
   }
   if (((int)ob->query_skill("huagong-dafa", 1) >0)||
       ((int)ob->query_skill("huntian-qigong", 1) >0)||
       ((int)ob->query_skill("hunyuan-yiqi", 1) >0)||
       ((int)ob->query_skill("linji-zhuang", 1) >0)||
       ((int)ob->query_skill("xuantian-force", 1) >0)||
       ((int)ob->query_skill("zixia-shengong", 1) >0))
   {
      message_vision("$N������ѧ̫���ˣ�ʵ�ھ�����������ڡ�\n",ob);
      return 1;
   }    
   if (
      arg == "liangyi-jian" ||
      arg == "tiyunzong")
   {
      if ((int)ob->query_skill(arg, 1) <100)
      {
         message_vision("$N��" + to_chinese(arg) + "��Ȼ̫�ͣ��޷�����ʯ�����ݡ�\n",ob);
         return 1;
      }
      if ((int)ob->query_skill(arg, 1) > 180)
      {
         message_vision("$N��" + to_chinese(arg) + "�Ѿ�û��Ҫ��ʯ�������ˡ�\n",
ob);
         return 1;
      }
      if(((ob->query_skill(arg,1)
        *ob->query_skill(arg,1)
        *ob->query_skill(arg,1)/10)> (int)ob->query("combat_exp"))
        && arg != "literate")
      {
         message_vision("$N��ʵս���鲻�㣬�޷�����ʯ�����ݡ�\n",ob);
         return 1;
      }
      if (ob->query("jing")<20)
      {
         message_vision("$N̫���ˣ������޷�����ʯ�����ݡ�\n",ob);
         return 1;
      }
      message_vision("$N�����ʯ��������˼�����ã���" + to_chinese(arg) + "��������\n",ob);
      ob->improve_skill(arg, random(10*ob->query("int")));
      ob->add("jing",-5);
      return 1;
   }
   message_vision("$N�����ʯ��������˼�����ã���������\n",ob);
   ob->add("jing",-5);
   return 1;
}
