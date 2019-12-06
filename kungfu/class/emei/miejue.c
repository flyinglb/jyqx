// miejue.c ���ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
        set_name("���ʦ̫", ({ "miejue shitai","miejue","shitai"}));
        set("long",
                "���Ƕ����ɵĵ��������ӣ����ζ����������ˡ�\n");
        set("gender", "Ů��");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );
        set("inquiry",([
                "���"  : "ƶ��ֻ֪����ɱħ������ȵ��ӡ�",
                "����"  : "ƶ��ֻ֪����ɱħ������ȵ��ӡ�",
                "����"  :  (: ask_for_quit :),
        ]));

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        set("per", 20);

        set("max_qi", 4000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 2000000);
        set("score", 1000);
        set_skill("persuading", 150);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 200);
        set_skill("blade", 200);
        set_skill("literate", 100);
        set_skill("mahayana", 200);
        set_skill("buddhism", 200);
        set_skill("jinding-zhang", 200);
        set_skill("tiangang-zhi", 200);
        set_skill("huifeng-jian", 200);
        set_skill("yanxing-dao", 200);
        set_skill("zhutian-bu", 200);
        set_skill("linji-zhuang", 200);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
//        map_skill("magic","bashi-shentong");
        create_family("������", 3, "������");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
   mapping ob_fam;

   string name, new_name;
   name = ob->query("name");

   if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
   {
      command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
      return;
   }
   switch (random(2))
   {
        case 1: break;
        default:
           if ((string)ob->query("class")!="bonze" )
           {
               command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
               return;
           }
           else
           {
               command ("say �����ӷ�ƶ�᲻�յ��ӡ�");
               return;
           }
   }
   if ((int)ob->query_skill("mahayana",1)<90||(int)ob->query_skill("linji-zhuang",1)<90)
   {
      command("say �㱾�ŵĹ�����Ϊ��̫�͡�");
      return;
   }
   if ((int)ob->query("shen") < 50000)
   {
      command("say " + RANK_D->query_respect(ob) + "����������֮�»����Ĳ�����");
      return;
   }
   if ((string)ob->query("class")=="bonze" )
   {
        name = ob->query("name");
        new_name = "��" + name[2..3];
        ob->set("name", new_name);
        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ���Ϊ���ҵ��Ĵ�����!");
   }

   command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
   command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������");
   command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "������")) 
        return ("��Ͷ���û��ԨԴ��ƶ�᲻�Ҹ��㻹�ס�\n");
    if( (string)me->query("class")!="bonze" )
        return "�����ӷ𣡳����˲���ڿ����Ѿ����׼����ˡ�\n";
    me->set_temp("pending/quit_bonze", 1);
        command ("say �����ӷ����գ����գ���һ��Ҫ���ף���Ҳ��������\n");
        command ("say �ҽ���ȥ�㲿���书�������(kneel)������\n");
        return "�����Ը���׵ģ��Ͱ����ڴ������ɡ�\n";
}

int do_kneel()
{
}

