// zhao.c ����ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{
        set_name("����ʦ̫", ({ "jingzhao shitai","jingzhao","shitai"}));
        set("long",
           "����һλ������ҵ��ã����ڸ�£����ü��Ŀ��\n");
        set("gender", "Ů��");
        set("age", 43);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "bonze");
        set("inquiry",([
                "���"  : (: ask_for_join :),
                "����"  : (: ask_for_join :),
                "����"  : "���ҵ��ӣ����ܻ��ס���������ʦ̫�ɡ�",
        ]));

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 20);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 150000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("throwing", 60);
        set_skill("force", 60);
        set_skill("dodge", 70);
        set_skill("finger", 60);
        set_skill("parry", 75);
        set_skill("strike", 70);
        set_skill("sword", 60);
        set_skill("mahayana", 60);
        set_skill("literate", 70);
        set_skill("jinding-zhang", 60);
        set_skill("tiangang-zhi", 70);
        set_skill("huifeng-jian", 60);
        set_skill("zhutian-bu", 60);
        set_skill("linji-zhuang", 60);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");

        create_family("������", 4, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}
void init()
{
        add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("class")!="bonze" )
   {
      command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�ʩ������ѧ�տ�ȥ�����׼�ʦ�á�");
      return;
   }
   if( (string)ob->query("gender") != "Ů��" )
   {
      command ("say �����ӷ�ƶ�᲻���е��ӡ�ʩ������ѧ�տ�ȥ�����׼�ʦ�á�");
      return;
   }
   if ((int)ob->query("shen") < 100)
   {
      command("say " + RANK_D->query_respect(ob) + "����������֮�»����Ĳ�����");
      return;
   }
   command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
   command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������");
   command("recruit " + ob->query("id"));
}

#include "tobebonze.h"
