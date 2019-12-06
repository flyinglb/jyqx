// zhou.c ������

#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "zhou zhiruo","zhiruo","zhou"}));
        set("long",
                "���Ƕ����ɵĵ��Ĵ����ŵ��ӡ�\n"
                "һ�����������ס�����һ�������ѡ�\n"
                "�����������Ц�д���Щ�����Ρ�\n"
                "���ܼ�į��\n");
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );
        set("inquiry",([
                "���"    : "������ȣ����԰ɡ�",
                "����"    : "Ҫ�������ҵ�ʦ����ȥ��",
                "����"    : "���ġ�����Ҳ���ң�",
                "���޼�"  : "������Ķ����ļһ����Ҳ��Ҫ������",
                "����"    : "��Ҫ���������ӣ�",
                "���콣"  : "ʦ������������ʦ��ˡ�",
                "������"  : "�������ֳ��ۣ��������ˡ�",
                "���ʦ̫"  : "ʦ���ѵ���ͽ�����Ȱͽ��Ұɡ�",
        ]));
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 3500);
        set("max_jing", 1000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jingli", 1000);
        set("max_jingli", 1000);

        set("combat_exp", 1500000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("force", 100);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("claw", 100);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("jinding-zhang", 100);
        set_skill("jiuyin-baiguzhao", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("huifeng-jian", 100);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 100);
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        create_family("������", 4, "���ŵ���");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/ycloth.c")->wear();
}

void attempt_apprentice(object ob)
{

   if (ob->query("shen")<100)
   {
       command("heng");
       command("say " + ob->query("name") + "������ʲô������͵�������ݣ����������ޣ�");
       command("!!! " + ob->query("id"));
       kill_ob(this_player());
   }
   else
      if ( ob->query_temp("marks/�η���") )
      {
        if ( (int)ob->query("combat_exp") > 100000 &&
             (int)ob->query("betrayer") > (int)ob->query("K_betrayer"))
        {
             command("heng");
             command("say �������������Ź棬���Ķ��⡣������������Ϊͽ��");
             return;
        }
        if ((int)ob->query("per") < 22 )
        {
            command("giggle");
            command("say ��λ"+RANK_D->query_respect(ob)+"��ò̫Ҳ...������������ذɣ�");
           return ;
        }
        if ((int)ob->query_dex() < 26  && (int)ob->query_int() < 28 )
        {
           command("say ��λ"+RANK_D->query_respect(ob)+"�������ʲ���һ�㡣");
           command("say �����д���Ǳ���������Ȼ�ȥĥ��ĥ����");
           return ;
        }
        command("say" + ob->query("name") + "������ô��������Ϊ����������ɡ�\n");
        command("recruit " + ob->query("id"));
        ob->delete_temp("marks/�η���");
      } 
      else command("say " + this_player()->query("name") + "��û�¾Ϳ������ˡ�\n\n");
   return;
}
