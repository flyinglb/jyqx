// fawang.h for fight and get letter from FaWang

void attempt_apprentice(object ob)
{

        if (ob->query("party/party_name") !=  HIG "����" NOR)
	{
                command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	else
	{
		command("say �������ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");
		command("say ��ϲ������Ϊ���̻�����");
		command("recruit " + ob->query("id"));
		ob->set("title", HIR"���̻���"NOR);
	}
	return;
}

#include "mingjiao.h"
