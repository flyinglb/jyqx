// xiaoheshang.c

inherit NPC;

void init();
int ask_dingli();
int ask_changli();
void greeting(object ob);
void serve_tea(object who);

void create()
{
      set_name("С����", ({ "xiao heshang" }) );
      set("gender", "����" );
      set("age", 14);
      set("long", "���Ǹ�������ɵ�С����\n");
      set("str", 15);
      set("dex", 20);
      set("con", 17);
      set("int", 15);
      set("shen_type", 1);

      set_skill("unarmed", 50);
      set_skill("dodge", 35);
      set_temp("apply/attack", 5);
      set_temp("apply/defense", 5);
      set("combat_exp", 7500);
      set("startroom","/u/solomon/workroom");

      set("attitude", "peaceful");
      set("inquiry", ([
            "����" : (: ask_dingli :),
            "����" : (: ask_changli :),
            "�����п�" : "������������Ȼ���ҵ����˶�����ʶ��\n",
      ]));
      set("chat_chance", 20);
      set("chat_msg", ({
            "���ް����ӷ�\n",
            "�������շ�������\n",
            "���޴�����������\n",
            "���޴�ȴ󱯹�����������\n",
            (: random_move :),
            (: random_move :),
      }) );
                      
      setup();
}

void init()
{
      object ob;

      ::init();

      if ( interactive(ob = this_player()) && !is_fighting() )
      {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
      }
}

void greeting(object ob)
{
      if ( environment(ob) != environment() )
            return;
      if (ob->query("id") == "solomon" )
            command("say ʦ��������");
      else
            command("hi "+ob->query("id"));
}

int ask_dingli()
{
      if ( this_player()->query("chanxin/save")>=2 )
      {
            command("say ������㻹����һ��ģ�\n");
            this_player()->set("chanxin/save",3);
      }
      else
      {
            command("say ����Ҵ��������������ԣ�\n");
      }
      return 1;
}

int ask_changli()
{
      if ( this_player()->query("chanxin/save")>=3 )
      {
            command("say ����ỹ����Ҫ��¥�����ȵ��ô��\n");
            this_player()->set("chanxin/save",4);
      }
      else
      {
            command("say ����Ҵ��������������ԣ�\n");
      }
      return 1;
}

void serve_tea(object who)
{
      object obn,room;

      if ( !who || environment(who) != environment() )
            return;

      if( !who->query_temp("marks/sit") )
            return;
      
      if( !objectp(room = environment()) )
            return;

      obn = new("d/wudang/obj/xiangcha");
      obn->move(room);
      message_vision("С�����ó���ɳС��������˱���裬�������ϣ�\n", who);

      obn = new("d/hangzhou/npc/obj/jiuping");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/pork");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/geng");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/shrimp");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/chicken");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/fish");
      obn->move(room);
      message_vision("Ȼ���ó�һƿ�ƺ�һ���̺óԵķ������ϣ�\n", who);
      
      return;
}
