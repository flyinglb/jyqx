// /d/xingxiu/npc/woman.c
// by mei
inherit NPC;
void create()
{
        set_name("����", ({ "aman", "girl" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "�������Ĺ����˹���,��������,��Ŀ毺�, �۹�����˸��Ц�⡣\n");
        set("shen_type", 1);
     set("per",30);
        set("shen", 200);
        set("combat_exp", 2000);
        set("str", 16);
        set("dex", 18);
        set("con", 12);
        set("int", 24);
        set("attitude", "friendly");
        set("inquiry", ([
            "����" : "����, �������㡣\n",
            "ë̺" : "����, �뵽��������ѡ��\n",
          "������" : "������һ���������ء�\n",
            "����" : "��һֱ��Ҫһ������, ֯�������ƵĶ�����\n",
          "��˿��" : "�������ġ���Ҫ����ʲô? \n",
            "ѩ��" : "��������ѩ������������ҵġ� \n",
        ]) );
        setup();
        add_money("silver", 30);
        carry_object(__DIR__"obj/qcloth")->wear();
}
int accept_object(object who, object ob)
{

        if ((string)ob->query("id")=="jin zhen")
          {
                        this_player()->set_temp("marks/����3", 1); {
                        write("��������˵��������ѩ����? \n");
                return 1;
                      }
                if( who->query_temp("marks/����2", 1) ) {
                        write("��������˵����һֻѩ����ô��? \n");
                        this_player()->set_temp("marks/����4", 1);
                        this_player()->set_temp("marks/����2", 0);
                        return 1;
                      }
                return 0;
          }
         if ((string)ob->query("id")=="xue can") {
                if( who->query_temp("marks/����4") ) {
                       write("��������˵������˿�������ˡ�\n");
                       say("��������" + who->query("name") + "һ����˿����\n");
                       this_player()->set_temp("marks/����4", 0);
                       new(__DIR__"obj/rousisuo")->move(who);
                       return 1;
                     }
                  if( who->query_temp("marks/����3", 1) ) {
                       write("��������˵����һֻѩ����ô��? \n");
                        this_player()->set_temp("marks/����4", 1);
                        this_player()->set_temp("marks/����3", 0);
                        return 1;
                     }
                  say("�����Ѳ���������˵������ô�ɰ��Ĳ�, �������\n");
                  return 1;
                }
           if ((string)ob->query("id")=="xue can") {
                  say("����Ц����˵������˿�������ˡ�\n");
                  return 1;
                }
            return 0;
      }

