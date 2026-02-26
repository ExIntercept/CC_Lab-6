pipeline {
    agent any

    stages {

        stage('Build Backend') {
            steps {
                sh '''
                echo "Building backend Docker image..."
                docker build -t backend-app backend
                '''
            }
        }

        stage('Run Backends') {
            steps {
                sh '''
                echo "Cleaning old containers..."
                docker rm -f backend1 backend2 nginx-lb || true
                docker network rm lab6-network || true

                echo "Creating Docker network..."
                docker network create lab6-network

                echo "Starting backend containers..."
                docker run -d --name backend1 --network lab6-network backend-app
                docker run -d --name backend2 --network lab6-network backend-app
                '''
            }
        }

        stage('Run NGINX Load Balancer') {
            steps {
                sh '''
                echo "Starting NGINX container..."
                docker run -d --name nginx-lb \
                --network lab6-network \
                -p 80:80 \
                nginx

                echo "Copying NGINX config..."
                docker cp nginx/default.conf nginx-lb:/etc/nginx/conf.d/default.conf

                echo "Reloading NGINX..."
                docker exec nginx-lb nginx -s reload
                '''
            }
        }
    }

    post {
        success {
            echo 'Pipeline completed successfully!'
        }
        failure {
            echo 'Pipeline failed. Check console output.'
        }
    }
}
