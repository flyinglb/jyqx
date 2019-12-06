// fengas.c
// edward.2000.3

inherit NPC;
//inherit F_MASTER;

#include <ansi.h>

string ask_me();

void create()
{
        set_name(HIC"�밢��"NOR, ({ "feng asan", "feng" }));
        set("long", 
                "��˵������³��ĺ��ˣ������ĵ�һ�ɽ�����ƻ��ص����֡�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "friendly");
        set("class", "alchemist");
        set("shen_type", 1);
        set("str", 38);
        set("int", 28);
        set("con", 30);
        set("dex", 28);

        set("inquiry", ([
                "����":(:ask_me:),
        ]) );

        set("max_qi", 600);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 30);
        set("combat_exp", 100000);
        set("score", 20000);

        set_skill("blade",50);
        set_skill("ruyi-dao",50);
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("lingboweibu", 50);
        set_skill("beiming-shengong",50);
        set_skill("liuyang-zhang", 50);

        map_skill("unarmed", "liuyang-zhang");
        map_skill("dodge", "lingboweibu");
        map_skill("force", "beiming-shengong");
        map_skill("blade", "ruyi-dao");

        create_family("��ң��", 3, "����");
        set("title","��ң��"MAG"�����Ȱ��ѡ�"NOR);
        set("nickname",HIY"�ɽ�"NOR);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/blade")->wield();

}

string ask_me()
{

        if (random(100)<70)
                return "������ƻ��ط������е��س����ô�Ҽ�Ц�ˡ�";   
        command("laugh");
        return "�����ң����ڿ����ء�������"HIY"֥�鿪��"NOR"���������������Ц\n";
}
