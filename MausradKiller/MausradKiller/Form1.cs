using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MausradKiller
{
	public partial class Form1 : Form
	{
		private Process cli = null;

		public Form1()
		{
			InitializeComponent();
		}

		private void Button1_Click(object sender, EventArgs e)
		{
			if (cli != null)
			{
				cli.Kill();
				cli = null;
				button1.Text = "Mausrad deaktivieren";
			}
			else
			{
				ProcessStartInfo startInfo = new ProcessStartInfo();
				startInfo.FileName = "MouseKillerCLI.exe";
				startInfo.Arguments = "";
				startInfo.RedirectStandardOutput = true;
				startInfo.RedirectStandardError = true;
				startInfo.UseShellExecute = false;
				startInfo.CreateNoWindow = true;

				cli = new Process();
				cli.StartInfo = startInfo;
				cli.EnableRaisingEvents = true;
				cli.Start();

				button1.Text = "Mausrad aktivieren";
			}
		}
	}
}
