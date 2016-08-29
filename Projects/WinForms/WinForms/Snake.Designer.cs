namespace WinForms
{
    partial class Snake
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.sCanvas = new System.Windows.Forms.PictureBox();
            this.score = new System.Windows.Forms.Label();
            this.scoreValue = new System.Windows.Forms.Label();
            this.gameTimer = new System.Windows.Forms.Timer(this.components);
            this.gameOver = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.sCanvas)).BeginInit();
            this.SuspendLayout();
            // 
            // sCanvas
            // 
            this.sCanvas.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.sCanvas.Location = new System.Drawing.Point(12, 12);
            this.sCanvas.Name = "sCanvas";
            this.sCanvas.Size = new System.Drawing.Size(691, 507);
            this.sCanvas.TabIndex = 0;
            this.sCanvas.TabStop = false;
            this.sCanvas.Paint += new System.Windows.Forms.PaintEventHandler(this.sCanvas_Paint);
            // 
            // score
            // 
            this.score.AutoSize = true;
            this.score.Location = new System.Drawing.Point(709, 39);
            this.score.Name = "score";
            this.score.Size = new System.Drawing.Size(35, 13);
            this.score.TabIndex = 1;
            this.score.Text = "Score";
            this.score.Click += new System.EventHandler(this.label1_Click);
            // 
            // scoreValue
            // 
            this.scoreValue.AutoSize = true;
            this.scoreValue.Location = new System.Drawing.Point(782, 39);
            this.scoreValue.Name = "scoreValue";
            this.scoreValue.Size = new System.Drawing.Size(0, 13);
            this.scoreValue.TabIndex = 2;
            // 
            // gameOver
            // 
            this.gameOver.AutoSize = true;
            this.gameOver.Location = new System.Drawing.Point(37, 37);
            this.gameOver.Name = "gameOver";
            this.gameOver.Size = new System.Drawing.Size(35, 13);
            this.gameOver.TabIndex = 3;
            this.gameOver.Text = "label1";
            this.gameOver.Visible = false;
            // 
            // Snake
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1106, 557);
            this.Controls.Add(this.gameOver);
            this.Controls.Add(this.scoreValue);
            this.Controls.Add(this.score);
            this.Controls.Add(this.sCanvas);
            this.KeyPreview = true;
            this.Name = "Snake";
            this.Text = "Snake";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Snake_KeyDown);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Snake_KeyPress);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Snake_KeyUp);
            ((System.ComponentModel.ISupportInitialize)(this.sCanvas)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox sCanvas;
        private System.Windows.Forms.Label score;
        private System.Windows.Forms.Label scoreValue;
        private System.Windows.Forms.Timer gameTimer;
        private System.Windows.Forms.Label gameOver;
    }
}