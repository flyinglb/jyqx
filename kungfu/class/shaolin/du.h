// du.h for fight and apprentice to 3-du

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("3du-ok")==1)
		{
			ob->delete_temp("3du-ok");
	
			if (ob->query_skill("dodge",1)>=120 &&
			ob->query_skill("force",1)>=120 &&
			ob->query_skill("parry",1)>=120 &&
			ob->query_skill("buddhism",1)>=120)
			{
			command("say ���ܹ���շ�ħȦ�������� !");
			command("say ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			name = ob->query("name");
			new_name = "��" + name[2..3];
			ob->set("name", new_name);
	
			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ����� !");
			command("recruit " + ob->query("id"));
			}
			else
			command("say ƶɮҪ�յ�������֮�ţ��㻹�ǻ�ȥ����ʦ��ѧϰ��!");
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "��û�ܹ���շ�ħȦ���Ҳ������㡣");
			return;
		}
	}
	return;
}

