// he.c ����ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����ʦ̫", ({ "jinghe shitai","jinghe","shitai"}));
        set("long",
            "����һλ������ҵ��ã����ڸ�£����ü��Ŀ��\n");
        set("gender", "Ů��");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "bonze");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 250000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("throwing", 70);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("finger", 90);
        set_skill("parry", 100);
        set_skill("strike", 100);
        set_skill("blade", 90);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("jinding-zhang", 90);
        set_skill("tiangang-zhi", 100);
        set_skill("yanxing-dao", 100);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 100);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("blade","yanxing-dao");
        map_skill("parry","yanxing-dao");

        create_family("������", 4, "����");

        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}
void attempt_apprentice(object ob)
{
    command ("say �����ӷ�ƶ�᲻�յ��ӡ�\n");
    command ("say ���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�\n");
    return;
}

